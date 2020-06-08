//
// Created by mati on 17.05.2020.
//

#include "Woda.h"
Woda::Woda(std::shared_ptr<drawNS::Draw3DAPI> ptrApi) : Powierzchnia(ptrApi) {

}


void Woda::Rysuj() {
     id_woda = api->draw_surface(std::vector<std::vector<Point3D> > {{
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
}
void Woda::Wymaz() {
    api->erase_shape(id_woda);
}

bool Woda::czy_kolizja(const Dron_interfejs &D) const {
    double tmp;
    tmp = D.get_srodek()[2];
    if ( tmp == PunktyPowierzchnii[0][2]) {
        std::cout<< "Nastapilo wynurzenie ponad powierzchnie wody! Wstrzymano ruch.";
        return true;
    } else
        return false;
}



