//
// Created by mati on 08.05.2020.
//

#include "MObrotu.h"

MObrotu::MObrotu() {
    for (int i = 0; i < ROZMIAR; i++) {
        tab[i] = SWektor<double, ROZMIAR>();
    }

    for (int i = 0; i < ROZMIAR; i++) {
        tab[i][i]=1;
    }
}


MObrotu::MObrotu(SMacierz<double, 3> MacObrotu) {

    double blad_obl = 0.0001;
    double tmp = 0;
    if ((std::abs(MacObrotu.wyznacznik()) -1 ) < blad_obl){
        for (int i = 0; i < ROZMIAR-1; i++) {
            for (int j = i+1; j<ROZMIAR; j++){
                tmp = MacObrotu[i] * MacObrotu[j];
            }
        }
        if (tmp < blad_obl){
            for (int i = 0; i < ROZMIAR; i++) {
                MObrotu::tab[i] = MacObrotu[i];
                }

        } else {
            std::cerr << "2 Blad. To nie jest macierz obrotu.";
            exit(1);
        }
    } else {
        std::cerr << "1 Blad. To nie jest macierz obrotu.";
        exit(1);
    }
}

MObrotu::MObrotu(char os, double kat) {
    double pi = 3.1415;
    kat = (kat * pi) / 90 ;

    switch(os) {
        case 'x' : {
            SWektor<double, ROZMIAR> W1(1, 0, 0);
            SWektor<double, ROZMIAR> W2(0, cos(kat), -sin(kat));
            SWektor<double, ROZMIAR> W3(0, sin(kat), cos(kat));
            tab[0] = W1;
            tab[1] = W2;
            tab[2] = W3;

            break;
        }
        case 'y' : {
            SWektor <double,ROZMIAR>  W1(cos(kat),0,sin(kat));
            SWektor <double,ROZMIAR>  W2(0,1,0);
            SWektor <double,ROZMIAR>  W3(-sin(kat),0,cos(kat));
            tab[0] = W1;
            tab[1] = W2;
            tab[2] = W3;
            break;
        }
        case 'z' : {
            SWektor<double, ROZMIAR> W1(cos(kat), -sin(kat), 0);
            SWektor<double, ROZMIAR> W2(sin(kat), cos(kat), 0);
            SWektor<double, ROZMIAR> W3(0, 0, 1);
            tab[0] = W1;
            tab[1] = W2;
            tab[2] = W3;
            break;
        }
        default:
            std::cerr << "Blad. Konstrukcja macierzy obrotu nie powiedla sie" ;
            exit(1);
    }

}




