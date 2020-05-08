//
// Created by mati on 08.05.2020.
//

#include "Bryla.h"

Bryla Bryla::Bryla_ObrocX(double kat) {
    Bryla Wynikowa;
    for(int i=0; i < Wierzcholki.size(); i++)
         Wynikowa.Wierzcholki[i] = MObrotu::Macierz_ObrotX(kat) * Wierzcholki[i];

    return Wynikowa;
}

Bryla Bryla::Bryla_ObrocY(double kat) {
    Bryla Wynikowa;
    for(int i=0; i < Wierzcholki.size(); i++)
        Wynikowa.Wierzcholki[i] = MObrotu::Macierz_ObrotY(kat) * Wierzcholki[i];

    return Wynikowa;
}

Bryla Bryla::Bryla_ObrocZ(double kat) {
    Bryla Wynikowa;
    for(int i=0; i < Wierzcholki.size(); i++)
        Wynikowa.Wierzcholki[i] = MObrotu::Macierz_ObrotZ(kat) * Wierzcholki[i];

    return Wynikowa;
}

