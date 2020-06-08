//
// Created by mati on 17.05.2020.
//

#ifndef DRON_V1_WODA_H
#define DRON_V1_WODA_H

#include "Powierzchnia.h"

class Woda : public Powierzchnia {

    uint id_woda;

public:
    Woda(std::shared_ptr<drawNS::Draw3DAPI> ptrApi);
    void Rysuj() override;
    void Wymaz() override;
    bool czy_kolizja(const Dron_interfejs &D) const override;


};


#endif //DRON_V1_WODA_H
