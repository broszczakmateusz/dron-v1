#include "SWektor.h"
#include "rozmiar.h"
#include <iostream>
#include "Dr3D_gnuplot_api.hh"
#include "Dron.h"
#include "Dno.h"
#include "Woda.h"
#include "Przeszkoda_Prost.h"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;
using std::cin;

int main() {
    /* Przygotowanie sceny*/
    std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-SCENA, SCENA,-SCENA, SCENA,-SCENA, SCENA,-1)); //włacza gnuplota, pojawia się scena [-5,5] x [-5,5] x [-5,5] odświeżana co 1000 ms
    SWektor<double, ROZMIAR> W1(1,1,1);
    SWektor<double, ROZMIAR> W2(70,80,10);
    Dron D1(api,W1);

    Dno D(api);
    Woda W(api);
    Przeszkoda_Prost P1(api, W2);


    D1.Rysuj();
    D.Rysuj();
    W.Rysuj();
    P1.Rysuj();
    api->redraw();
    D1.Obroc(0);

    api->change_ref_time_ms(0); //odświeżanie sceny zmienione na opcję "z każdym pojawieniem się lub zniknięciem kształtu

   /* Menu*/
    char wybor = 'x';

   while (wybor != 'k') {
       cout << "r - zadaj ruch na wprost \n";
       cout << "o - zadaj zmiane orientacji \n";
       cout << "k - koniec \n";

       cin >> wybor;
       switch (wybor) {
           case 'r' : {
           double kat_wznop;
           double odleglosc;
           cout << "Twoj wybor - ruch na wprost. \n";

           cout << "Podaj wartosc kata (wznoszenia/opadania) w stopniach. ";
           cin >> kat_wznop;
           cout << "Podaj wartosc odleglosci, na ktora ma sie przemiescic dron. ";
           cin >> odleglosc;
           D1.Przesun(odleglosc, kat_wznop);
           break;
           }
           case 'o' : {
           double kat_obr;
           cout << "Twoj wybor - zamiana orientaji. \n";
           cout << "Podaj wartosc kata obrotu w stopniach. ";
           cin >> kat_obr;
           D1.Obroc(kat_obr);
           break;
           }
           case 'k': {
           cout << "Koniec dzialania programu.\n"<< "\n";
           cout <<"Liczba wszystkich utworznych bryl: "<< Bryla::Ile_wszystkich<< "\n";
           cout <<"Liczba aktualnie instniejacych bryl: "<< Bryla::Ile_istnieje<< "\n";
           cout <<"Liczba wszystkich utworznych wektorow: "<< SWektor<double,ROZMIAR>::Ile_wszystkich<< "\n";
           cout <<"Liczba aktualnie instniejacych wektorow: "<< SWektor<double,ROZMIAR>::Ile_istnieje<< "\n";
           exit(0);
           break;
           }
           default: {
           cout << "Blad. \n";
           break;
           }
       }
   }
    return 0;
}
