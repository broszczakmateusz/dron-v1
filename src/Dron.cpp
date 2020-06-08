//
// Created by mati on 08.05.2020.
//

#include <unistd.h>
#include "Dron.h"

Dron::Dron(std::shared_ptr<drawNS::Draw3DAPI> ptrApi, const SWektor<double, ROZMIAR> &sr) : Prostopadloscian(ptrApi, sr)/*, Sruba(ptrApi, sr)*/{

    Sruba TmpLewa(ptrApi,  Prostopadloscian::Wierzcholki[0]);
    Lewa = TmpLewa;
    Sruba TmpPrawa(ptrApi, Prostopadloscian::Wierzcholki[1]);
    Prawa = TmpPrawa;

    SWektor<double,ROZMIAR> tmp;
    tmp = Prostopadloscian::srodek - Prostopadloscian::Wierzcholki[0];
    r_dron = tmp.dlugosc();

}

void Dron::Obroc(double kat) {

    int klatki = 100;
    double kat_klatke = kat/klatki;
    for (int i = 0; i <klatki; i++) {
        Prostopadloscian::Obroc(kat_klatke);
        Lewa.Obroc(kat_klatke);
        Prawa.Obroc(kat_klatke);
/*        if (kat > 0)
            Prawa.Wiruj();
        else if(kat < 0)
            Lewa.Wiruj();*/
    }
}

void Dron::Rysuj() {
    Prostopadloscian::Rysuj();
    Lewa.Rysuj();
    Prawa.Rysuj();

}

void Dron::Przesun(double odleglosc, double kat) {

    int klatki = 10;
    double odl_klatki = odleglosc / klatki;
    double kat_klatki = kat / klatki;
    for (int i = 0; i <klatki; i++) {
        std::cout << "krok "<<i<<"\n";
        Prostopadloscian::Przesun(odl_klatki, kat_klatki);
/*        Lewa.Przesun(odl_klatki, kat_klatki);
        Prawa.Przesun(odl_klatki, kat_klatki);*/
    }
    Lewa.Przesun(-odleglosc, kat);
    Prawa.Przesun(-odleglosc, kat);

}

double Dron::get_r() const {
    return r_dron;
}
const SWektor<double, ROZMIAR> Dron::get_srodek() const {
    return Prostopadloscian::srodek;
}