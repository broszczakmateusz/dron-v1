#include <iomanip>
#include "SWektor.h"
#include "rozmiar.h"
#include <iostream>
#include "Dr3D_gnuplot_api.hh"
#include "Bryla.h"
#include "Dron.h"

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

    //Dron Submarine;

   std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-100,100,-100,100,-100,100,1000)); //włacza gnuplota, pojawia się scena [-5,5] x [-5,5] x [-5,5] odświeżana co 1000 ms

  //  api->change_ref_time_ms(0); //odświeżanie sceny zmienione na opcję "z każdym pojawieniem się lub zniknięciem kształtu"

  api->draw_polyhedron(vector<vector<Point3D> > {{
       drawNS::Point3D(0,0,0), drawNS::Point3D(0,20,0), drawNS::Point3D(40,20,0), drawNS::Point3D(40,0,0)
    },{
       drawNS::Point3D(0,0,10), drawNS::Point3D(0,20,10), drawNS::Point3D(40,20,10), drawNS::Point3D(40,0,10)
    }},"red");//rysuje czerewony graniastosłup


    /* Rysuje dno*/
   int dno = api->draw_surface(vector<vector<Point3D> > {{
            drawNS::Point3D(-90,90,-90), drawNS::Point3D(-30,90,-90), drawNS::Point3D(30,90,-90), drawNS::Point3D(90,90,-90),
    },{
            drawNS::Point3D(-90,60,-90), drawNS::Point3D(-30,60,-90), drawNS::Point3D(30,60,-90), drawNS::Point3D(90,60,-90),
    },{
            drawNS::Point3D(-90,30,-90), drawNS::Point3D(-30,30,-90), drawNS::Point3D(30,30,-90), drawNS::Point3D(90,30,-90),
    },{
            drawNS::Point3D(-90,0,-90), drawNS::Point3D(-30,0,-90), drawNS::Point3D(30,0,-90), drawNS::Point3D(90,0,-90),
    },{
            drawNS::Point3D(-90,-30,-90), drawNS::Point3D(-30,-30,-90), drawNS::Point3D(30,-30,-90), drawNS::Point3D(90,-30,-90),
    },{
            drawNS::Point3D(-90,-60,-90), drawNS::Point3D(-30,-60,-90), drawNS::Point3D(30,-60,-90), drawNS::Point3D(90,-60,-90),
    },{
            drawNS::Point3D(-90,-90,-90), drawNS::Point3D(-30,-90,-90), drawNS::Point3D(30,-90,-90), drawNS::Point3D(90,-90,-90),
}},"yellow");//rysuje żółta powierzchnię dna
    cout << "pojawiła się szara powierzchnia" << endl;

    /* Rysuje powierzchnie wody*/
   int powierzchnia_wody = api->draw_surface(vector<vector<Point3D> > {{
            drawNS::Point3D(-90,90,50), drawNS::Point3D(-30,90,50), drawNS::Point3D(30,90,50), drawNS::Point3D(90,90,50),
    },{
            drawNS::Point3D(-90,60,50), drawNS::Point3D(-30,60,50), drawNS::Point3D(30,60,50), drawNS::Point3D(90,60,50),
    },{
            drawNS::Point3D(-90,30,50), drawNS::Point3D(-30,30,50), drawNS::Point3D(30,30,50), drawNS::Point3D(90,30,50),
    },{
            drawNS::Point3D(-90,0,50), drawNS::Point3D(-30,0,50), drawNS::Point3D(30,0,50), drawNS::Point3D(90,0,50),
    },{
            drawNS::Point3D(-90,-30,50), drawNS::Point3D(-30,-30,50), drawNS::Point3D(30,-30,50), drawNS::Point3D(90,-30,50),
    },{
            drawNS::Point3D(-90,-60,50), drawNS::Point3D(-30,-60,50), drawNS::Point3D(30,-60,50), drawNS::Point3D(90,-60,50),
    },{
            drawNS::Point3D(-90,-90,50), drawNS::Point3D(-30,-90,50), drawNS::Point3D(30,-90,50), drawNS::Point3D(90,-90,50),
    }},"blue");//rysuje niebieska powierzchnie wody
    cout << "pojawiła się szara powierzchnia" << endl;
    wait4key();

}
