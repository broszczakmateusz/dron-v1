//
// Created by mati on 16.05.2020.
//

#ifndef DRON_V1_RYSUJ_INTERFEJS_H
#define DRON_V1_RYSUJ_INTERFEJS_H

#include "Draw3D_api_interface.hh"
#include "Dr3D_gnuplot_api.hh"

/*!
 * \brief Abstrakcyjna klasa, interfejs rysowania
 */
class Rysuj_interfejs {
public:
/*!
* \brief Wskaźnik na api do Gnuplota.
*/
    std::shared_ptr<drawNS::Draw3DAPI> api;

/*!
 * \brief Konstruktor domyslny
 */
    Rysuj_interfejs() = default;
/*!
* \brief Konstruktor
 * \param ptrApi - wskaznik na api do Gnuplota
*/
    Rysuj_interfejs(std::shared_ptr<drawNS::Draw3DAPI> ptrApi): api(ptrApi) {} ;
/*!
* \brief Wirtualny dekonstruktor
*/
   virtual  ~Rysuj_interfejs() = default;
/*!
* \brief wirtualna metoda rysujaca
*/
     virtual void Rysuj() = 0;
/*!
* \brief wirtualna metoda wymazujaca
*/
   virtual void Wymaz() = 0;
};


#endif //DRON_V1_RYSUJ_INTERFEJS_H
