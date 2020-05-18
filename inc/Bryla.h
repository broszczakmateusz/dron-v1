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
     * \brief Konstruktor
     * \param ptrApi - wskaźnik na api.
     * \param sr - punkt reprezentujacy srodek.
     * \param orient - macierz obrotu reprezentujaca orientacje bryly.
     * */
    Bryla(std::shared_ptr<drawNS::Draw3DAPI> ptrApi, const SWektor<double, ROZMIAR> &sr) :
    Rysuj_interfejs(ptrApi),  srodek(sr), id(0){} ;
    /*!
     * \brief Dekonstruktor wirtualny
     * */
    virtual  ~Bryla() {};
    /*!
    * \brief Obraca bryłę.
    * \param kat - wartosc kata w stopniach o jaki ma zostac obrocona bryla wokol osi OZ.
    */
    virtual void Obroc(double kat) =0;
    /*!
    * \brief Przesuwa śrdodek bryły o dany wektor.
    * \param odleglosc - wektor przesunięcia.
    */
    virtual void Przesun(double odleglosc, double kat) =0;
    /*!
    * \brief Wirtyalna metoda rysujaca bryle.
    * \param odleglosc - o jaka ma zostac przesuneta bryla.
     * \param kat - kat opadania/wznoszenia.
    */
    //virtual void Rysuj() = 0;
    void Wymaz() override {api->erase_shape(id); }
};


#endif //DRON_V1_BRYLA_H
