//
// Created by yutong pang on 6/28/15.
//

#include "EMField_2D_TMz.h"
#include <math.h>

EMField2DTMz::EMField2DTMz(): EMFieldabstract(1.0 / sqrt(2.0)) {
    Ez.assign(STRUCTURE_SIZE_X, std::vector<double> (STRUCTURE_SIZE_Y, 0.0));
    Hx.assign(STRUCTURE_SIZE_X, std::vector<double> (STRUCTURE_SIZE_Y - 1, 0.0));
    Hy.assign(STRUCTURE_SIZE_X - 1, std::vector<double> (STRUCTURE_SIZE_Y, 0.0));
}

void EMField2DTMz::updateMagneticField() {
    size_t ygridsize = Ez[0].size();
    size_t xgridsize = Ez.size();
    int xgridpoint;
    int ygridpoint;
    for (xgridpoint = 0; xgridpoint < xgridsize; xgridpoint++) {
        for (ygridpoint = 0; ygridpoint < ygridsize - 1; ygridpoint++) {
            Hx[xgridpoint][ygridpoint] =
                    getChxh(xgridpoint) * Hx[xgridpoint][ygridpoint] -
                    getChxe(xgridpoint) * (Ez[xgridpoint][ygridpoint + 1] - Ez[xgridpoint][ygridpoint]);
        }
    }
    for (xgridpoint = 0; xgridpoint < xgridsize - 1; xgridpoint++) {
        for (ygridpoint = 0; ygridpoint < ygridsize; ygridpoint++) {
            Hy[xgridpoint][ygridpoint] =
                    getChyh(xgridpoint) * Hy[xgridpoint][ygridpoint] +
                    getChye(xgridpoint) * (Ez[xgridpoint + 1][ygridpoint] - Ez[xgridpoint][ygridpoint]);
        }
    }
}

void EMField2DTMz::updateElectricField() {
    size_t ygridsize = Ez[0].size();
    size_t xgridsize = Ez.size();
    int xgridpoint;
    int ygridpoint;
    for (xgridpoint = 1; xgridpoint < xgridsize - 1; xgridpoint++) {
        for (ygridpoint = 1; ygridpoint < ygridsize - 1; ygridpoint++) {
            Ez[xgridpoint][ygridpoint] = getCeze(xgridpoint) * Ez[xgridpoint][ygridpoint] + getCezh(xgridpoint) *
                                                                                  ((Hy[xgridpoint][ygridpoint] -
                                                                                    Hy[xgridpoint - 1][ygridpoint]) -
                                                                                   (Hx[xgridpoint][ygridpoint] -
                                                                                    Hx[xgridpoint][ygridpoint - 1]));
        }
    }

}

double EMField2DTMz::getChxh(const int gridpoint) const {
    return (1.0- structure.loss[gridpoint])/(1.0 + structure.loss[gridpoint]);
}

double EMField2DTMz::getChxe(const int gridpoint) const {
    return Cdtds / IMP0 / (1.0 + structure.loss[gridpoint]);
}

