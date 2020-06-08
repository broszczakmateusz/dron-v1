// Created by mati on 07.06.2020.
//

#ifndef DRON_V1_DRON_INTERFEJS_H
#define DRON_V1_DRON_INTERFEJS_H
#include "SWektor.h"
/*!
 * \brief Abstrakcyjna klasa, interfejs drona
 */
class Dron_interfejs {
public:
/*!
 * \brief Konstruktor domyslny
*/
    Dron_interfejs() = default;
/*!
* \brief Wirtualna metoda obracajaca dorna wokol osi Z o podany kat.
 * \param kat - wartosc kata obrotu w stopniach.
*/
   virtual void Obroc(double kat) = 0;
/*!
* \brief Wirtualna metoda rysujaca drona.
*/
   virtual void Rysuj() = 0;
/*!
* \brief Wirtualna metoda przesuwajaca drona.
 * \param odleglosc - zadana odleglosc na jaka ma sie przesunac dron.
 * \param kat - zadany kat wznoszenia/opadania
*/
   virtual void Przesun(double odleglosc, double kat) = 0;
/*!
* \brief Wirtualna metoda, zwraca pole r_dron
*/
   virtual double get_r() const = 0;
/*!
* \brief Wirtualna metoda, zwraca srodek drona
*/
   virtual const SWektor<double, ROZMIAR> get_srodek() const = 0;
};


#endif //DRON_V1_DRON_INTERFEJS_H
