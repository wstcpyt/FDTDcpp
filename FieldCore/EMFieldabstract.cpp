//
// Created by yutong pang on 7/8/15.
//

#include "EMFieldabstract.h"

EMFieldabstract::EMFieldabstract(const double Cdtds, const Structure& structure): Cdtds(Cdtds), structure(structure) {
    Ez.assign(STRUCTURE_SIZE, 0.0);
    Hy.assign(STRUCTURE_SIZE - 1, 0.0);
}


const double EMFieldabstract::getCeze(const int gridpoint) const {
    return (1.0- structure.loss[gridpoint])/(1.0 + structure.loss[gridpoint]);
}

const double EMFieldabstract::getCezh(const int gridpoint) const {
    return Cdtds * IMP0 / structure.permittivity[gridpoint]/ (1.0 + structure.loss[gridpoint]);
}

const double EMFieldabstract::getChyh(const int gridpoint) const {
    return (1.0- structure.loss[gridpoint])/(1.0 + structure.loss[gridpoint]);
}

const double EMFieldabstract::getChye(const int gridpoint) const {
    return Cdtds / IMP0 / (1.0 + structure.loss[gridpoint]);
}