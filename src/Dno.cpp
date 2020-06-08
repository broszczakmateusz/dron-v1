//
// Created by mati on 17.05.2020.
//

#include "Dno.h"



Dno::Dno(std::shared_ptr<drawNS::Draw3DAPI> ptrApi) : Powierzchnia(ptrApi) {

}

void Dno::Rysuj() {
    id_dno = api->draw_surface(std::vector<std::vector<Point3D> > {{
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
}
void Dno::Wymaz() {
    api->erase_shape(id_dno);
}

bool Dno::czy_kolizja(const Dron_interfejs &D) const {
    double tmp;
    tmp = D.get_srodek()[2] - D.get_r();
    if ( tmp == PunktyPowierzchnii[0][2]) {
        std::cout<< "Nastapila kolizja z dnem! Wstrzymano ruch.";
        return true;
    } else
        return false;
}
