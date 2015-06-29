//
// Created by yutong pang on 6/24/15.
//

#include "EMField.h"
EMField::EMField() {
    permittivity = structure.getPermittivity();
    loss = structure.getLoss();
}

void EMField::updateElectricField(std::vector<double> &Ez, std::vector<double> &Hy) const {
    unsigned long gridsize = Ez.size();
    int gridpoint;
    for(gridpoint = 1; gridpoint < gridsize - 1; gridpoint++){
        double electricUpdateC_E = getElectricUpdateC_E(gridpoint);
        double electricUpdateC_H = getElectricUpdateC_H(gridpoint);
        Ez[gridpoint] =  electricUpdateC_E * Ez[gridpoint] + electricUpdateC_H * (Hy[gridpoint] - Hy[gridpoint - 1]) ;
    }
}

void EMField::updateMagneticField(std::vector<double> &Ez, std::vector<double> &Hy) const {
    unsigned long gridsize = Ez.size();
    int gridpoint;
    for(gridpoint = 0; gridpoint < gridsize - 1; gridpoint++){
        double magneticUpdateC_H = getMagneticUpdateC_H(gridpoint);
        double magneticUpdateC_E = getMagneticUpdateC_E(gridpoint);
        Hy[gridpoint] = magneticUpdateC_H * Hy[gridpoint] + magneticUpdateC_E * (Ez[gridpoint + 1] - Ez[gridpoint]);
    }
}

const double EMField::getElectricUpdateC_E(const int gridpoint) const {
    return (1.0- loss[gridpoint])/(1.0 + loss[gridpoint]);
}

const double EMField::getElectricUpdateC_H(const int gridpoint) const {
    return IMP0 / permittivity[gridpoint]/ (1.0 + loss[gridpoint]);
}

const double EMField::getMagneticUpdateC_H(const int gridpoint) const {
    return (1.0- loss[gridpoint])/(1.0 + loss[gridpoint]);
}

const double EMField::getMagneticUpdateC_E(const int gridpoint) const {
    return 1.0 / IMP0 / (1.0 + loss[gridpoint]);
}
