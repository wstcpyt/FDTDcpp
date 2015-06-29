//
// Created by yutong pang on 6/28/15.
//

#include "EMField_2D_TMz.h"

void EMField2DTMz::updateMagneticField(std::vector<std::vector<double>> &Ez, std::vector<std::vector<double>> &Hx,
                                       std::vector<std::vector<double >> &Hy) const {
    unsigned long ygridsize = Ez.size();
    unsigned long xgridsize = Ez[0].size();
    int xgridpoint;
    int ygridpoint;
    for (xgridpoint = 0; xgridpoint < xgridsize; xgridpoint++) {
        for (ygridpoint = 0; ygridpoint < ygridsize - 1; ygridpoint++) {
            Hx[xgridpoint][ygridpoint] =
                    getChxh() * Hx[xgridpoint][ygridpoint] -
                    getChxe() * (Ez[xgridpoint][ygridpoint + 1] - Ez[xgridpoint][ygridpoint]);
        }
    }
    for (xgridpoint = 0; xgridpoint < xgridsize - 1; xgridpoint++) {
        for (ygridpoint = 0; ygridpoint < ygridsize; ygridpoint++) {
            Hy[xgridpoint][ygridpoint] =
                    getChyh() * Hy[xgridpoint][ygridpoint] -
                    getChye() * (Ez[xgridpoint + 1][ygridpoint] - Ez[xgridpoint][ygridpoint]);
        }
    }
}

void EMField2DTMz::updateElectricField(std::vector<std::vector<double>> &Ez, std::vector<std::vector<double>> &Hx,
                                       std::vector<std::vector<double >> &Hy) const {
    unsigned long ygridsize = Ez.size();
    unsigned long xgridsize = Ez[0].size();
    int xgridpoint;
    int ygridpoint;
    for (xgridpoint = 1; xgridpoint < xgridsize - 1; xgridpoint++) {
        for (ygridpoint = 1; ygridpoint < ygridsize - 1; ygridpoint++) {
            Ez[xgridpoint][ygridpoint] = getCeze() * Ez[xgridpoint][ygridpoint] + getCezh() *
                                                                                  ((Hy[xgridpoint][ygridpoint] -
                                                                                    Hy[xgridpoint - 1][ygridpoint]) -
                                                                                   (Hx[xgridpoint][ygridpoint] -
                                                                                    Hx[xgridpoint][ygridpoint - 1]));
        }
    }

}

double EMField2DTMz::getChxh() const {
    return 1.0;
}

double EMField2DTMz::getChxe() const {
    return Cdtds / IMP0;
}

double EMField2DTMz::getChyh() const {
    return 1.0;
}

double EMField2DTMz::getChye() const {
    return Cdtds / IMP0;
}

double EMField2DTMz::getCezh() const {
    return Cdtds * IMP0;
}

double EMField2DTMz::getCeze() const {
    return 1.0;
}