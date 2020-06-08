//
// Created by mati on 07.06.2020.
//

#ifndef DRON_V1_PRZESZKODA_H
#define DRON_V1_PRZESZKODA_H

#include "Dron_interfejs.h"

class Przeszkoda {
public:
    virtual bool czy_kolizja(const Dron_interfejs &D) const = 0;
    virtual void Rysuj() = 0;
};


#endif //DRON_V1_PRZESZKODA_H
