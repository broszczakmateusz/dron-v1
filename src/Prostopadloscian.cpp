//
// Created by mati on 10.05.2020.
//

#include <unistd.h>
#include "Prostopadloscian.h"

using std::vector;
using drawNS::Point3D;
using std::shared_ptr;

Prostopadloscian::Prostopadloscian(std::shared_ptr<drawNS::Draw3DAPI> ptrApi, const SWektor<double,ROZMIAR> &sr) :
        Bryla(ptrApi,sr) {

    Wierzcholki[0] = SWektor<double,ROZMIAR>(srodek[0] -20, srodek[1] -10, srodek[2] -5);
    Wierzcholki[1] = SWektor<double,ROZMIAR>(srodek[0] -20, srodek[1] +10, srodek[2] -5);
    Wierzcholki[2] = SWektor<double,ROZMIAR>(srodek[0] +20, srodek[1] +10, srodek[2] -5);
    Wierzcholki[3] = SWektor<double,ROZMIAR>(srodek[0] +20, srodek[1] -10, srodek[2] -5);

    Wierzcholki[4] = SWektor<double,ROZMIAR>(srodek[0] -20, srodek[1] -10, srodek[2] +5);
    Wierzcholki[5] = SWektor<double,ROZMIAR>(srodek[0] -20, srodek[1] +10, srodek[2] +5);
    Wierzcholki[6] = SWektor<double,ROZMIAR>(srodek[0] +20, srodek[1] +10, srodek[2] +5);
    Wierzcholki[7] = SWektor<double,ROZMIAR>(srodek[0] +20, srodek[1] -10, srodek[2] +5);

}

void Prostopadloscian::Rysuj() {

    for (int i = 0; i<8; i++) {
        Wierzcholki[i] = Wierzcholki[i] - srodek;
        Wierzcholki[i] = orientacja * Wierzcholki[i] + srodek;
//        std::cout <<"Wierzchilki["<<i<<"] "<< Wierzcholki[i] <<"\n";
    }

    id = api->draw_polyhedron(vector<vector<drawNS::Point3D>> {
        {Wierzcholki[0], Wierzcholki[1], Wierzcholki[2], Wierzcholki[3]},
        {Wierzcholki[4], Wierzcholki[5], Wierzcholki[6], Wierzcholki[7]}
        },"red");

    api->redraw();

}

void Prostopadloscian::Obroc(double kat) {
    MObrotu Mtmp('z', kat);

    //srodek = Mtmp * srodek;
    orientacja = Mtmp * orientacja;
    api->erase_shape(id);
    this->Rysuj();

}

void Prostopadloscian::Przesun(double odleglosc, double kat) {

    //if(std::fmod(kat,180)) {
        /*Animacja wznoszenia/opadania*/
        //ObrocY(kat);
        SWektor<double, ROZMIAR> WPrze(odleglosc * cos(kat)  ,0,odleglosc * sin(kat));
//        std::cout <<"wprze "<< WPrze<<"\n";

    for (int i = 0; i<8; i++) {
        Wierzcholki[i] = Wierzcholki[i] - WPrze;
//        std::cout <<"xxW["<<i<<"] "<< Wierzcholki[i] <<"\n";
    }

        srodek = srodek + WPrze;
//    std::cout <<"srodek "<< srodek <<"\n";
        api->erase_shape(id);
        this->Rysuj();
        /* Powrot do poziomu */
        //ObrocY(-kat);

/*    } else {
        //ObrocY(0);
        SWektor<double, ROZMIAR> WPrze(odleglosc,0,0);
        srodek = srodek + WPrze;
        api->erase_shape(id);
        this->Rysuj();
    }*/
}

void Prostopadloscian::ObrocY(double kat) {
    int klatki = 100;
    double kat_klatke = -kat/klatki;
    MObrotu Mtmp('y', kat_klatke);

    srodek = Mtmp * srodek;
    for (int i = 0; i <klatki; i++) {

        orientacja = Mtmp * orientacja;

        usleep(0.000001);
        api->erase_shape(id);
        this->Rysuj();

    }
}
