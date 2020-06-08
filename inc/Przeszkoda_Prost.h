//
// Created by mati on 07.06.2020.
//

#ifndef DRON_V1_PRZESZKODA_PROST_H
#define DRON_V1_PRZESZKODA_PROST_H

#include "Przeszkoda.h"
#include "Prostopadloscian.h"

class Przeszkoda_Prost: public Przeszkoda, public Prostopadloscian {

     double r_przeszkoda;
public:
    Przeszkoda_Prost(std::shared_ptr<drawNS::Draw3DAPI> ptrApi, const SWektor<double,ROZMIAR> &sr);
    void Rysuj() override;
    bool czy_kolizja(const Dron_interfejs &D)const override;
};


#endif //DRON_V1_PRZESZKODA_PROST_H
