//
// Created by mati on 28.05.2020.
//

#ifndef DRON_V1_SRUBA_H
#define DRON_V1_SRUBA_H


#include "Bryla.h"

class Sruba: Bryla {

    SWektor <double,ROZMIAR> Wierzcholki[12];

public:
    Sruba(){};
    Sruba(std::shared_ptr<drawNS::Draw3DAPI> ptrApi,  SWektor<double, ROZMIAR> punkt);
    void Rysuj() override;
    void Obroc(double kat) override ;
    void Przesun(double odleglosc, double kat) override ;
    void ObrocY(double kat);
    void Wiruj();
};


#endif //DRON_V1_SRUBA_H
