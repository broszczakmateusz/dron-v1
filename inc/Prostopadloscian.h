//
// Created by mati on 10.05.2020.
//

#ifndef DRON_V1_PROSTOPADLOSCIAN_H
#define DRON_V1_PROSTOPADLOSCIAN_H

#include <vector>
#include "SMacierz.h"
#include "Bryla.h"

class Prostopadloscian : public Bryla {

protected:
    std::vector<SWektor<double,ROZMIAR>> Wierzcholki;
    void Prostopadloscian_Obroc();
    void Prostopadloscian_Przesun(const SWektor<double, 3> &Przesun);
    // Prostopadloscian_Rysuj();
};


#endif //DRON_V1_PROSTOPADLOSCIAN_H
