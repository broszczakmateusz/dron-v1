//
// Created by mati on 08.05.2020.
//

#include "MObrotu.h"

SMacierz<double, ROZMIAR> MObrotu::Macierz_ObrotX(double kat) {
    SWektor <double,ROZMIAR>  W1(1,0,0);
    SWektor <double,ROZMIAR>  W2(0,cos(kat),-sin(kat));
    SWektor <double,ROZMIAR>  W3(0,sin(kat),cos(kat));

    return SMacierz<double, 3>(W1, W2, W3);
}

SMacierz<double, ROZMIAR> MObrotu::Macierz_ObrotY(double kat) {

    SWektor <double,ROZMIAR>  W1(cos(kat),0,sin(kat));
    SWektor <double,ROZMIAR>  W2(0,1,0);
    SWektor <double,ROZMIAR>  W3(-sin(kat),0,cos(kat));

    return SMacierz<double, 3>(W1, W2, W3);
}

SMacierz<double, ROZMIAR> MObrotu::Macierz_ObrotZ(double kat) {

    SWektor <double,ROZMIAR>  W1(cos(kat),-sin(kat),0);
    SWektor <double,ROZMIAR>  W2(cos(kat),sin(kat),0);
    SWektor <double,ROZMIAR>  W3(0,0,1);

    return SMacierz<double, 3>(W1, W2, W3);
}

