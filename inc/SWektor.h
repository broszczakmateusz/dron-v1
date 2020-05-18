#ifndef SZABLON_Z4_MASTER_SWEKTOR_H
#define SZABLON_Z4_MASTER_SWEKTOR_H

#include "rozmiar.h"
#include <iostream>
#include <cmath>
#include "Dr3D_gnuplot_api.hh"

using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

/*
 *  Klasa modeluje pojecie szabloonu wektora o wymiarze ROZMIAR;
 */
template <class TYP, int Rozmiar>
class SWektor {

    TYP dane[ROZMIAR];

public:
    SWektor() { for (TYP &i: dane) i = 0; }
    SWektor(TYP x, TYP y, TYP z);
    explicit SWektor(TYP wspolrzedne[ROZMIAR]); //konstruktor od kolekcji

    const TYP & operator[] (int indeks) const;
    TYP & operator[] (int indeks);

    SWektor<TYP, Rozmiar> operator + (const SWektor<TYP, Rozmiar> & W2) const;
    SWektor<TYP, Rozmiar> operator - (const SWektor<TYP, Rozmiar> & W2) const;
    TYP operator * (const SWektor<TYP, Rozmiar> & W2) const;

    SWektor<TYP, Rozmiar>  operator * (TYP liczba) const;
    SWektor<TYP, Rozmiar>  operator / (TYP liczba) ;

    operator drawNS::Point3D(){ return drawNS::Point3D(dane[0],dane[1], dane[2]);}

};
/* Wczytuje tablice wartowsci double lub liczb zespolonych, tworzy z nich wektor.*/
template <class TYP, int Rozmiar>
std::istream& operator >> (std::istream & Strm, SWektor<TYP, Rozmiar> &Wek);

/* Wsywietla na standardowym wyjsciu wektor.*/
template <class TYP, int Rozmiar>
std::ostream& operator << (std::ostream & Strm, const SWektor<TYP, Rozmiar> & Wek);


#endif
