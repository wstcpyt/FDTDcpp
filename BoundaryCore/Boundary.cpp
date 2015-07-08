//
// Created by yutong pang on 6/26/15.
//

#include "Boundary.h"
#include <math.h>

Boundary::Boundary() {
}

void Boundary::addMagteticABC(EMField& emField) const {
    size_t size = emField.Hy.size();
    emField.Hy[size - 1] = emField.Hy[size - 2];
}

void Boundary::addElectricABC(EMField& emField) const {
    emField.Ez[0] = emField.Ez[1];
}

void Boundary::addMagneticTFSF(const int &time, const int &sourcelocation, EMField& emField) const {
    emField.Hy[sourcelocation - 1] -= exp(-(time - 30.) * (time - 30.) / 100.) / IMP0;
}

void Boundary::addElectricTFSF(const int &time, const int &sourcelocation, EMField& emField) const {
    emField.Ez[sourcelocation] += exp(-(time + 0.5 -(-0.5) -30.)* (time + 0.5 - (-0.5) -30.) / 100.);
}

void Boundary::addElectricFirstABC(EMField& emField)  {
    /* ABC for left side of grid */
    emField.Ez[0] =  ezOldLeft + updateCpattern(1 / (sqrt( structure.permittivity[0]) )) * (emField.Ez[1] - emField.Ez[0]);
    ezOldLeft = emField.Ez[1];
    /* ABC for right side of grid */
    size_t size = emField.Ez.size();
    emField.Ez[size - 1] = ezOldRight + updateCpattern(1 / (sqrt( structure.permittivity[size - 1]) )) * (emField.Ez[size - 2] - emField.Ez[size - 1]);
    ezOldRight = emField.Ez[size - 2];
}

double Boundary::updateCpattern(const double parameter) const {
    return (parameter - 1.0) / (parameter + 1.0);
}
