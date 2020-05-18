//
// Created by mati on 08.05.2020.
//

#ifndef DRON_V1_MOBROTU_H
#define DRON_V1_MOBROTU_H

#include "SMacierz.h"
#include <cmath>

class MObrotu : public SMacierz <double,  ROZMIAR>{

public:
    MObrotu(SWektor<double,ROZMIAR> W1, SWektor<double,ROZMIAR> W2, SWektor<double,ROZMIAR> W3) : SMacierz(W1, W2, W3){};
    MObrotu();
    MObrotu(char os, double kat);
    MObrotu(SMacierz<double, ROZMIAR> MacObrotu);

};


#endif //DRON_V1_MOBROTU_H
