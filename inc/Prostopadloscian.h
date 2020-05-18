//
// Created by mati on 10.05.2020.
//

#ifndef DRON_V1_PROSTOPADLOSCIAN_H
#define DRON_V1_PROSTOPADLOSCIAN_H

#include <vector>
#include "SMacierz.h"
#include "Bryla.h"
#include "Draw3D_api_interface.hh"
#include "MObrotu.h"

class Prostopadloscian : public Bryla {

protected:
    SWektor<double,ROZMIAR> Wierzcholki[8];
    SWektor<double,ROZMIAR> PPrzod[4];


public:
    Prostopadloscian(std::shared_ptr<drawNS::Draw3DAPI> ptrApi, const SWektor<double, ROZMIAR> &sr);
    void Rysuj() override;
    void Obroc(double kat) override ;
    void Przesun(double odleglosc, double kat) override ;

};


#endif //DRON_V1_PROSTOPADLOSCIAN_H
