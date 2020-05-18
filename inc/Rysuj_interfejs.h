//
// Created by mati on 16.05.2020.
//

#ifndef DRON_V1_RYSUJ_INTERFEJS_H
#define DRON_V1_RYSUJ_INTERFEJS_H

#include "Draw3D_api_interface.hh"
#include "Dr3D_gnuplot_api.hh"

class Rysuj_interfejs {

public:

    Rysuj_interfejs(std::shared_ptr<drawNS::Draw3DAPI> ptrApi): api(ptrApi) {}
    virtual  ~Rysuj_interfejs() {};
    virtual void Rysuj() = 0;
    virtual void Wymaz() = 0;

/*!
* \brief Wskaźnik na api do Gnuplota.
*/
    std::shared_ptr<drawNS::Draw3DAPI> api;
};


#endif //DRON_V1_RYSUJ_INTERFEJS_H
