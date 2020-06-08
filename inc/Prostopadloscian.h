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
/*!
* \brief Klasa definiujaca prostopadloscian w przestrzeni 3D
*/
class Prostopadloscian : public Bryla {

protected:
/*!
* \brief tablica 8 punktow reprezentujacych polozenie wierzcholkow prostopadloscianu.
*/
    SWektor<double,ROZMIAR> Wierzcholki[8];

public:
/*!
* \brief Konstruktor domyslny
*/
    Prostopadloscian() = default;
/*!
* \brief Konstruktor
 * \param ptrApi - wskaznik na api do Gnuplota
 * \param sr - punkt reprezentujacy srodek prostopadloscianu
*/
    Prostopadloscian(std::shared_ptr<drawNS::Draw3DAPI> ptrApi, const SWektor<double, ROZMIAR> &sr);
/*!
* \brief Metoda rysujaca prostopadloscian.
*/
    void Rysuj() override;
/*!
* \brief Metoda obracajaca prostopadloscian wokol osi Z o podany kat.
 * \param kat - wartosc kata obrotu w stopniach.
*/
    void Obroc(double kat) override ;
/*!
* \brief Pomocnicza metoda obracajaca prostopadloscian wokol osi Y o podany kat.
 * \param kat - wartosc kata obrotu w stopniach.
*/
    void ObrocY(double kat);
/*!
* \brief Metoda przesuwajaca prostopadloscian.
 * \param odleglosc - zadana odleglosc na jaka ma sie przesunac prostopadloscian
 * \param kat - zadany kat wznoszenia/opadania
*/
    void Przesun(double odleglosc, double kat) override ;

};


#endif //DRON_V1_PROSTOPADLOSCIAN_H
