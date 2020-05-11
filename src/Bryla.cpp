//
// Created by mati on 08.05.2020.
//

#include "Bryla.h"

void Bryla::Obroc() {
    SWektor<double, ROZMIAR> Nsrodek;
    Nsrodek = MObrotu::Macierz_ObrotZ(orientacja) * srodek;
}

void Bryla::Przesun(const SWektor<double, 3> &Przesun) {
    srodek = srodek + Przesun;
}
