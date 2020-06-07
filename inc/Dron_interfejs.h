// Created by mati on 07.06.2020.
//

#ifndef DRON_V1_DRON_INTERFEJS_H
#define DRON_V1_DRON_INTERFEJS_H


class Dron_interfejs {

public:
   virtual void Obroc(double kat) = 0;
   virtual void Rysuj() = 0;
   virtual void Przesun(double odleglosc, double kat) = 0;
};


#endif //DRON_V1_DRON_INTERFEJS_H
