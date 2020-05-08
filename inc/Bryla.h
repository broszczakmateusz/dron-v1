//
// Created by mati on 08.05.2020.
//

#ifndef DRON_V1_BRYLA_H
#define DRON_V1_BRYLA_H

#include <vector>
#include "SMacierz.h"
#include "MObrotu.h"

class Bryla {
    std::vector<SWektor<double,ROZMIAR>> Wierzcholki;

    Bryla Bryla_ObrocX(double kat);
    Bryla Bryla_ObrocY(double kat);
    Bryla Bryla_ObrocZ(double kat);
};


#endif //DRON_V1_BRYLA_H
