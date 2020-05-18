//
// Created by mati on 17.05.2020.
//

#ifndef DRON_V1_POWIERZCHNIA_H
#define DRON_V1_POWIERZCHNIA_H

#include <vector>
#include <memory>
#include "SWektor.h"
#include "Rysuj_interfejs.h"

class Powierzchnia : public Rysuj_interfejs {

protected:
    std::vector<SWektor<double, ROZMIAR>> PunktyPowierzchnii;

public:
    Powierzchnia(std::shared_ptr<drawNS::Draw3DAPI> ptrApi) : Rysuj_interfejs(ptrApi) {};

    virtual  ~Powierzchnia() {};

    virtual void Rysuj() = 0;

    virtual void Wymaz() = 0;
};
#endif //DRON_V1_POWIERZCHNIA_H