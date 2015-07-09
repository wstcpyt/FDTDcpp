//
// Created by yutong pang on 6/28/15.
//

#include "RickerWaveletSource.h"
void RickerWaveletSource::addRickerWaveletSource(const int &positionx, const int &positiony, const double &time,
                                                 const double &location,EMField2DTMz& emField2DTMz) const {
    double arg = M_PI * ((Cdtds * time - location) / PPW - 1.0);
    arg = arg * arg;
    double updatevalue = (1.0 - 2.0 * arg) * exp(-arg);
    emField2DTMz.Ez[positionx][positiony] = updatevalue;
}