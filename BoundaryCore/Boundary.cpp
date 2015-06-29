//
// Created by yutong pang on 6/26/15.
//

#include "Boundary.h"
#include <math.h>

Boundary::Boundary() {
    permittivity = structure.getPermittivity();
}

void Boundary::addMagteticABC(std::vector<double>& HGrid_y) const {
    unsigned long size = HGrid_y.size();
    HGrid_y[size - 1] = HGrid_y[size - 2];
}

void Boundary::addElectricABC(std::vector<double> &EGrid_z) const {
    EGrid_z[0] = EGrid_z[1];
}

void Boundary::addMagneticTFSF(const int &time, const int &sourcelocation, std::vector<double> &HGrid_y) const {
    HGrid_y[sourcelocation - 1] -= exp(-(time - 30.) * (time - 30.) / 100.) / IMP0;
}

void Boundary::addElectricTFSF(const int &time, const int &sourcelocation, std::vector<double> &EGrid_z) const {
    EGrid_z[sourcelocation] += exp(-(time + 0.5 -(-0.5) -30.)* (time + 0.5 - (-0.5) -30.) / 100.);
}

void Boundary::addElectricFirstABC(std::vector<double> &EGrid_z)  {
    /* ABC for left side of grid */
    EGrid_z[0] =  ezOldLeft + updateCpattern(1 / (sqrt( permittivity[0]) )) * (EGrid_z[1] - EGrid_z[0]);
    ezOldLeft = EGrid_z[1];
    /* ABC for right side of grid */
    unsigned long size = EGrid_z.size();
    EGrid_z[size - 1] = ezOldRight + updateCpattern(1 / (sqrt( permittivity[size - 1]) )) * (EGrid_z[size - 2] - EGrid_z[size - 1]);
    ezOldRight = EGrid_z[size - 2];
}

double Boundary::updateCpattern(const double parameter) const {
    return (parameter - 1.0) / (parameter + 1.0);
}
