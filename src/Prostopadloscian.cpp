//
// Created by mati on 10.05.2020.
//

#include "Prostopadloscian.h"

void Prostopadloscian::Prostopadloscian_Obroc() {

    for (int i =0; i < Wierzcholki.size(); i++)
        Wierzcholki[i] = MObrotu::Macierz_ObrotZ(orientacja) * Wierzcholki[i];

}

void Prostopadloscian::Prostopadloscian_Przesun(const SWektor<double, 3> &Przesun) {

    for (int i =0; i < Wierzcholki.size(); i++)
        Wierzcholki[i] = Wierzcholki[i] + Przesun;
}
