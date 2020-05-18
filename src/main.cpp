#include <iomanip>
#include "SWektor.h"
#include "rozmiar.h"
#include <iostream>
#include "Dr3D_gnuplot_api.hh"
#include "Bryla.h"
#include "Dron.h"
#include "Prostopadloscian.h"
#include "Dno.h"
#include "Woda.h"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;


void wait4key() {
    do {
        std::cout << "\n Press a key to continue..." << std::endl;
    } while(std::cin.get() != '\n');
}

int main() {
    std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-100,100,-100,100,-100,100,0)); //włacza gnuplota, pojawia się scena [-5,5] x [-5,5] x [-5,5] odświeżana co 1000 ms

    SWektor<double, ROZMIAR> W(0,0,0);
    Prostopadloscian pp(api,W);
    Dno d(api);
    Woda w(api);
   // api->change_ref_time_ms(0); //odświeżanie sceny zmienione na opcję "z każdym pojawieniem się lub zniknięciem kształtu"

    d.Rysuj();
    w.Rysuj();
    pp.Rysuj();
    wait4key();
    pp.Przesun(50,45);
    //pp.Obroc(135);

    wait4key();
}
