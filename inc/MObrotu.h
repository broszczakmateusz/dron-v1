//
// Created by mati on 08.05.2020.
//

#ifndef DRON_V1_MOBROTU_H
#define DRON_V1_MOBROTU_H

#include "SMacierz.h"
#include <cmath>

class MObrotu : public SMacierz <double,  ROZMIAR>{

double KatObrotu = 0;

public:

    MObrotu(SMacierz<double, ROZMIAR> MacObrotu);

    static SMacierz<double, ROZMIAR> Macierz_ObrotX(double kat);
    static SMacierz<double, ROZMIAR> Macierz_ObrotY(double kat);
    static SMacierz<double, ROZMIAR> Macierz_ObrotZ(double kat);

};


#endif //DRON_V1_MOBROTU_H
