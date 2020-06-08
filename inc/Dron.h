#ifndef DRON_V1_DRON_H
#define DRON_V1_DRON_H

#include <vector>
#include "SMacierz.h"
#include "MObrotu.h"
#include "Dron_interfejs.h"
#include "Prostopadloscian.h"
#include "Sruba.h"
#include "Przeszkoda.h"

/*!
 * \brief Klasa definiujaca podwodnego drona.
 * Dron sklada sie z prostopadloscianu i dwoch wirnikow.
 */
class Dron : public Dron_interfejs, public Prostopadloscian /*, public Sruba*/ /*, public Przeszkoda*/ {
/*!
 * \brief Pola reprezentujace wirniki drona.
 */
    Sruba Lewa, Prawa;
/*!
 * \brief Pole reprezentujace odleglosc od srodka do wierzcholka.
 */
    double r_dron;
public:
/*!
* \brief Konstruktor
 * \param ptrApi - wskaznik na api do Gnuplota
 * \param sr - punkt reprezentujacy srodek prostopadloscianu
*/
    Dron(std::shared_ptr<drawNS::Draw3DAPI> ptrApi, const SWektor<double, ROZMIAR> &sr);
/*!
* \brief Metoda obracajaca dorna wokol osi Z o podany kat.
 * \param kat - wartosc kata obrotu w stopniach.
*/
    void Obroc(double kat) override;
/*!
* \brief Metoda rysujaca drona.
*/
    void Rysuj() override;
/*!
* \brief Metoda przesuwajaca drona.
 * \param odleglosc - zadana odleglosc na jaka ma sie przesunac dron.
 * \param kat - zadany kat wznoszenia/opadania
*/
    void Przesun(double odleglosc, double kat) override;
/*!
* \brief zwraca pole r_dron
*/
    double get_r() const override;
/*!
* \brief zwraca srodek drona
*/
    const SWektor<double, ROZMIAR> get_srodek() const override;
};


#endif //DRON_V1_DRON_H
