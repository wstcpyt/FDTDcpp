//
// Created by yutong pang on 6/24/15.
//

#include "EMField.h"
EMField::EMField() : EMFieldabstract(1.0) {
}

void EMField::updateElectricField() {
    size_t gridsize = Ez.size();
    int gridpoint;
    for(gridpoint = 1; gridpoint < gridsize - 1; gridpoint++){
        double electricUpdateC_E = getCeze(gridpoint);
        double electricUpdateC_H = getCezh(gridpoint);
        Ez[gridpoint] =  electricUpdateC_E * Ez[gridpoint] + electricUpdateC_H * (Hy[gridpoint] - Hy[gridpoint - 1]) ;
    }
}

void EMField::updateMagneticField() {
    size_t gridsize = Ez.size();
    int gridpoint;
    for(gridpoint = 0; gridpoint < gridsize - 1; gridpoint++){
        double magneticUpdateC_H = getChyh(gridpoint);
        double magneticUpdateC_E = getChye(gridpoint);
        Hy[gridpoint] = magneticUpdateC_H * Hy[gridpoint] + magneticUpdateC_E * (Ez[gridpoint + 1] - Ez[gridpoint]);
    }
}