//
// Created by mati on 08.05.2020.
//

#ifndef DRON_V1_BRYLA_H
#define DRON_V1_BRYLA_H

#include <vector>
#include <memory>
#include "SWektor.h"
#include "SMacierz.h"
#include "MObrotu.h"
#include "Rysuj_interfejs.h"
/*!
 * \brief Definiuje klasę bryły w przestrzeni 3D.
 */
class Bryla : public Rysuj_interfejs {

protected:
    /*!
    * \brief Punkt o współrzędnych x, y, z, środek bryły.
    */
    SWektor<double,ROZMIAR> srodek;
    /*!
    * \brief Macierz opisujaca orientację bryLy względem osi OZ.
    */
    MObrotu orientacja = MObrotu('z',0);
    /*!
    * \brief Nazwa obiektu.
    */
    uint id;

public:
    /*!
* \brief liczba wszytskich utworzonych bryl
*/
    static int Ile_wszystkich;
    /*!
    * \brief liczba aktualnie utworzonych bryl
    */
    static int Ile_istnieje;


    /*!
    * \brief metoda zwracajaca liczbae wszytskich utworzonych bryl
    */
    static int get_wszystkie() { return Bryla::Ile_wszystkich;}
    /*!
    * \brief metoda zwracajaca liczbae aktualnie utworzonych bryl
    */
    static int get_ist() { return Bryla::Ile_istnieje ;}
    /*!
     * \brief Konstruktor domyslny
     * */
    Bryla() : Rysuj_interfejs() {Bryla::Ile_wszystkich++, Bryla::Ile_istnieje++;}

    /*!
     * \brief Konstruktor
     * \param ptrApi - wskaźnik na api.
     * \param sr - punkt reprezentujacy srodek.
     * */
    Bryla(std::shared_ptr<drawNS::Draw3DAPI> ptrApi, const SWektor<double, ROZMIAR> &sr) :
    Rysuj_interfejs(ptrApi),  srodek(sr), id(0) {Bryla::Ile_wszystkich++, Bryla::Ile_istnieje++;}
    /*!
     * \brief Konstruktor kopiujacy
     * \param B - kopiowana bryla
     * */
    Bryla(const Bryla &B) : srodek(B.srodek), orientacja(B.orientacja), id(B.id) {Bryla::Ile_wszystkich++, Bryla::Ile_istnieje++;}
    /*!
     * \brief Destruktor
     * */
    ~Bryla() {Bryla::Ile_istnieje--;}
    /*!
    * \brief Wirtualna metoda obracajaca bryłę.
    * \param kat - wartosc kata w stopniach o jaki ma zostac obrocona bryla wokol osi OZ.
    */
    virtual void Obroc(double kat) = 0;
    /*!
    * \brief Wirtualna metoda przesuwajaca śrdodek bryły o dany wektor.
    * \param odleglosc - wektor przesunięcia.
     * \param kat - zadany kat wznoszenia/opadania
    */
    virtual void Przesun(double odleglosc, double kat) = 0;
    /*!
    * \brief Wirtyalna metoda rysujaca bryle.
    */
    virtual void Rysuj() = 0;
    /*!
    * \brief Metoda wymazujaca bryle.
    */
    void Wymaz() override {api->erase_shape(id); }

};

#endif //DRON_V1_BRYLA_H
