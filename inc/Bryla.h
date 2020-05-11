//
// Created by mati on 08.05.2020.
//

#ifndef DRON_V1_BRYLA_H
#define DRON_V1_BRYLA_H

#include <vector>
#include <memory>
#include "SMacierz.h"
#include "MObrotu.h"
#include "Draw3D_api_interface.hh"
/*!
 * \brief Definiuje klasę bryły w przestrzeni 3D.
 */
class Bryla : public drawNS::Draw3DAPI{

public:
    /*!
    * \brief Punkt o współrzędnych x, y, z, środek bryły.
    */
    SWektor<double,ROZMIAR> srodek;
    /*!
    * \brief Kąt opisujacy obrót bryLy względem osi OZ.
    */
    double orientacja;
    /*!
    * \brief Wskaźnik na api do Gnuplota.
    */
    std::shared_ptr<drawNS::Draw3DAPI> ptr_na_api;

protected:
    /*!
    * \brief Obraca bryłę.
    */
    void Obroc();
    /*!
    * \brief Przesuwa śrdodek bryły o dany wektor.
     * \param Przesun - wektor przesunięcia.
    */
    void Przesun(const SWektor<double,ROZMIAR> &Przesun);
    // Bryla_rysuj();
};


#endif //DRON_V1_BRYLA_H
