//
// Created by mati on 07.06.2020.
//

#include "Przeszkoda_Prost.h"

Przeszkoda_Prost::Przeszkoda_Prost(std::shared_ptr<drawNS::Draw3DAPI> ptrApi, const SWektor<double,ROZMIAR> &sr)
        : Prostopadloscian(ptrApi, sr) {
    for (int i = 0; i<8; i++) {
        Wierzcholki[i] = Wierzcholki[i] /2;
    }
    SWektor<double,ROZMIAR> tmp;
    tmp = srodek - Wierzcholki[0];
    r_przeszkoda = tmp.dlugosc();
}
void Przeszkoda_Prost::Rysuj() {

Prostopadloscian::Rysuj();
    api->change_shape_color(id,"green");
    api->redraw();
}

bool Przeszkoda_Prost::czy_kolizja(const Dron_interfejs &D)const {
    double suma_r = r_przeszkoda + D.get_r();
    SWektor<double,ROZMIAR> tmp;
    tmp = srodek - D.get_srodek();
    if ( tmp.dlugosc() <  suma_r) {
        std::cout<< "Nastapila kolizja z przeszkoada! Wstrzymano ruch.";
        return true;
    } else
        return false;
}
