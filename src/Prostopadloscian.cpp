//
// Created by mati on 10.05.2020.
//

#include "Prostopadloscian.h"

using std::vector;
using drawNS::Point3D;
using std::shared_ptr;

Prostopadloscian::Prostopadloscian(std::shared_ptr<drawNS::Draw3DAPI> ptrApi, const SWektor<double,ROZMIAR> &sr) :
        Bryla(ptrApi,sr) {
    Wierzcholki[0] = SWektor<double,ROZMIAR>( -20,  -10,  -5);
    Wierzcholki[1] = SWektor<double,ROZMIAR>( -20, +10,  -5);
    Wierzcholki[2] = SWektor<double,ROZMIAR>( +20,  +10,  -5);
    Wierzcholki[3] = SWektor<double,ROZMIAR>( +20,  -10, -5);


    Wierzcholki[4] = SWektor<double,ROZMIAR>( -20, -10,  +5);
    Wierzcholki[5] = SWektor<double,ROZMIAR>( -20,  +10,  +5);
    Wierzcholki[6] = SWektor<double,ROZMIAR>(+20,  +10,  +5);
    Wierzcholki[7] = SWektor<double,ROZMIAR>(+20,  -10,  +5);

    PPrzod[0] = SWektor<double,ROZMIAR>( +20, 0,  0);
    PPrzod[1] = SWektor<double,ROZMIAR>( +20,  0,  0);
    PPrzod[2] = SWektor<double,ROZMIAR>(+20,  0,  0);
    PPrzod[3] = SWektor<double,ROZMIAR>(+20,  0,  0);
/*
    Wierzcholki[0] = SWektor<double,ROZMIAR>(srodek[0] -20, srodek[1] -10, srodek[2] -5);
    Wierzcholki[1] = SWektor<double,ROZMIAR>(srodek[0] -20, srodek[1] +10, srodek[2] -5);
    Wierzcholki[2] = SWektor<double,ROZMIAR>(srodek[0] +20, srodek[1] +10, srodek[2] -5);
    Wierzcholki[3] = SWektor<double,ROZMIAR>(srodek[0] +20, srodek[1] -10, srodek[2] -5);


    Wierzcholki[4] = SWektor<double,ROZMIAR>(srodek[0] -20, srodek[1] -10, srodek[2] +5);
    Wierzcholki[5] = SWektor<double,ROZMIAR>(srodek[0] -20, srodek[1] +10, srodek[2] +5);
    Wierzcholki[6] = SWektor<double,ROZMIAR>(srodek[0] +20, srodek[1] +10, srodek[2] +5);
    Wierzcholki[7] = SWektor<double,ROZMIAR>(srodek[0] +20, srodek[1] -10, srodek[2] +5);

*/

}

void Prostopadloscian::Rysuj() {


    Wierzcholki[0] = SWektor<double,ROZMIAR>(srodek[0] -20, srodek[1] -10, srodek[2] -5);
    Wierzcholki[1] = SWektor<double,ROZMIAR>(srodek[0] -20, srodek[1] +10, srodek[2] -5);
    Wierzcholki[2] = SWektor<double,ROZMIAR>(srodek[0] +20, srodek[1] +10, srodek[2] -5);
    Wierzcholki[3] = SWektor<double,ROZMIAR>(srodek[0] +20, srodek[1] -10, srodek[2] -5);


    Wierzcholki[4] = SWektor<double,ROZMIAR>(srodek[0] -20, srodek[1] -10, srodek[2] +5);
    Wierzcholki[5] = SWektor<double,ROZMIAR>(srodek[0] -20, srodek[1] +10, srodek[2] +5);
    Wierzcholki[6] = SWektor<double,ROZMIAR>(srodek[0] +20, srodek[1] +10, srodek[2] +5);
    Wierzcholki[7] = SWektor<double,ROZMIAR>(srodek[0] +20, srodek[1] -10, srodek[2] +5);

    PPrzod[0] = SWektor<double,ROZMIAR>(srodek[0] +20, 0,  0);
    PPrzod[1] = SWektor<double,ROZMIAR>(srodek[0] +20, 0,  0);
    PPrzod[2] = SWektor<double,ROZMIAR>(srodek[0] +20, 0,  0);
    PPrzod[3] = SWektor<double,ROZMIAR>(srodek[0] +20, 0,  0);

    for (int i = 0; i<8; i++) {
        Wierzcholki[i] = orientacja * Wierzcholki[i] ;
    }

    id = api->draw_polyhedron(vector<vector<drawNS::Point3D>> {
        {Wierzcholki[0], Wierzcholki[1], Wierzcholki[2], Wierzcholki[3]},
        {Wierzcholki[4], Wierzcholki[5], Wierzcholki[6], Wierzcholki[7]}
        },"red");

    api->redraw();

}

void Prostopadloscian::Obroc(double kat) {
    int klatki = 2;
    double kat_klatke = kat/klatki;
    MObrotu Mtmp('z', kat_klatke);
    MObrotu Mtmp2('z', kat);

    for (int i = 0; i <=klatki; i++) {
        orientacja = Mtmp;
        srodek = Mtmp * srodek;
        api->erase_shape(id);
        this->Rysuj();
    }
}

void Prostopadloscian::Przesun(double odleglosc, double kat) {
    MObrotu ObrY('y', kat);
    SWektor<double, ROZMIAR> WPrze(odleglosc,odleglosc,odleglosc);
    // WPrze = ObrY * WPrze;
    srodek =  srodek + orientacja * ObrY * WPrze;
    api->erase_shape(id);
    this->Rysuj();
}

