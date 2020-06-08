//
// Created by mati on 28.05.2020.
//

#include <unistd.h>
#include "Sruba.h"

using std::vector;
using drawNS::Point3D;
using std::shared_ptr;
Sruba::Sruba(std::shared_ptr<drawNS::Draw3DAPI> ptrApi, SWektor<double,ROZMIAR> punkt) : Bryla(ptrApi, punkt) {

    SWektor<double,ROZMIAR> korekta(2,0,0);
    srodek = punkt - korekta;

    double tmp = 3 * sqrt(3);

    Wierzcholki[0] = SWektor<double,ROZMIAR>(srodek[0] -2, srodek[1] -3, srodek[2] );
    Wierzcholki[1] = SWektor<double,ROZMIAR>(srodek[0] -2, srodek[1] -1.5, srodek[2] +tmp);
    Wierzcholki[2] = SWektor<double,ROZMIAR>(srodek[0] -2, srodek[1] +1.5, srodek[2] +tmp);
    Wierzcholki[3] = SWektor<double,ROZMIAR>(srodek[0] -2, srodek[1] +3, srodek[2] );
    Wierzcholki[4] = SWektor<double,ROZMIAR>(srodek[0] -2, srodek[1] +1.5, srodek[2] -tmp);
    Wierzcholki[5] = SWektor<double,ROZMIAR>(srodek[0] -2, srodek[1] -1.5, srodek[2] -tmp);

    Wierzcholki[6] = SWektor<double,ROZMIAR>(srodek[0] +2, srodek[1] -3, srodek[2] );
    Wierzcholki[7] = SWektor<double,ROZMIAR>(srodek[0] +2, srodek[1] -1.5, srodek[2] +tmp);
    Wierzcholki[8] = SWektor<double,ROZMIAR>(srodek[0] +2, srodek[1] +1.5, srodek[2] +tmp);
    Wierzcholki[9] = SWektor<double,ROZMIAR>(srodek[0] +2, srodek[1] +3, srodek[2] );
    Wierzcholki[10] = SWektor<double,ROZMIAR>(srodek[0] +2, srodek[1] +1.5, srodek[2] -tmp);
    Wierzcholki[11] = SWektor<double,ROZMIAR>(srodek[0] +2, srodek[1] -1.5, srodek[2] -tmp);


}

void Sruba::Rysuj() {
    api->erase_shape(Sruba::id);
    std::cout <<"srodek "<< srodek <<"\n";
    for (int i = 0; i<12; i++) {
       Wierzcholki[i] =   Wierzcholki[i] -  srodek;
       Wierzcholki[i] =   Wierzcholki[i] + orientacja * srodek;

       std::cout <<"Sruba ["<<i<<"] "<< Wierzcholki[i] <<"\n";
    }

    Sruba::id = api->draw_polyhedron(vector<vector<drawNS::Point3D>> {
        {Wierzcholki[0], Wierzcholki[1], Wierzcholki[2], Wierzcholki[3], Wierzcholki[4], Wierzcholki[5]},
        {Wierzcholki[6], Wierzcholki[7], Wierzcholki[8], Wierzcholki[9], Wierzcholki[10], Wierzcholki[11],}
    },"red");


    api->redraw();

}

void Sruba::Obroc(double kat) {
    MObrotu Mtmp('z', kat/2);

    srodek = Mtmp * srodek;
    orientacja = Mtmp * orientacja;
    api->erase_shape(Sruba::id);
    this->Rysuj();

}

void Sruba::Przesun(double odleglosc, double kat) {



//    if(std::fmod(kat,180)) {
        //ObrocY(kat);
        SWektor<double, ROZMIAR> WPrze(odleglosc * cos(kat)  ,0,odleglosc * sin(kat));
        std::cout <<"wprze "<< WPrze<<"\n";
        for (int i = 0; i<12; i++) {
            Wierzcholki[i] = Wierzcholki[i] - WPrze;
        }

        srodek = srodek + WPrze;
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

void Sruba::ObrocY(double kat) {
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

void Sruba::Wiruj() {
    double kat = 30;
    SWektor <double,ROZMIAR> tmp;
    tmp = srodek;
   /* int klatki = 100;
    double kat_klatke = -kat/klatki;
    MObrotu Mtmp('x', kat_klatke);*/
    MObrotu Mtmp('x', kat);
    tmp = Mtmp * tmp;
    api->erase_shape(id);
    this->Rysuj();

    /*srodek = Mtmp * srodek;
    for (int i = 0; i <klatki; i++) {

        orientacja = Mtmp * orientacja;

        usleep(0.000001);
        api->erase_shape(id);
        this->Rysuj();
    }*/

}
