//
// Created by yutong pang on 6/24/15.
//

#include "EMField.h"
EMField::EMField(const Structure& structure) : EMFieldabstract(1.0, structure) {
}

void EMField::updateElectricField() {
    size_t gridsize = Ez.size();
    int gridpoint;
    for(gridpoint = 1; gridpoint < gridsize - 1; gridpoint++){
        Ez[gridpoint] =  getCeze(gridpoint) * Ez[gridpoint] + getCezh(gridpoint) * (Hy[gridpoint] - Hy[gridpoint - 1]) ;
    }
}

void EMField::updateMagneticField() {
    size_t gridsize = Ez.size();
    int gridpoint;
    for(gridpoint = 0; gridpoint < gridsize - 1; gridpoint++){
        Hy[gridpoint] = getChyh(gridpoint) * Hy[gridpoint] + getChye(gridpoint) * (Ez[gridpoint + 1] - Ez[gridpoint]);
    }
}