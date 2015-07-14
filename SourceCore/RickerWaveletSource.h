//
// Created by yutong pang on 6/28/15.
//

#ifndef FDTDCPP_RICKERWAVELETSOURCE_H
#define FDTDCPP_RICKERWAVELETSOURCE_H

#include <math.h>
#include <vector>
#include "constant.h"
#include "FieldCore/EMField_2D_TMz.h"
#include "FieldCore/EMField.h"
#define PPW 100
class RickerWaveletSource{
    const double Cdtds {1.0 / sqrt(2.0)};
public:
    RickerWaveletSource(){};
    ~RickerWaveletSource(){};
    void addRickerWaveletSource (const int& positionx, const int& positiony, const double& time, const double& location, EMField2DTMz& emField2DTMz) const;
    double addRickerWaveletSource (const double& time, const double& location) const;
};
#endif //FDTDCPP_RICKERWAVELETSOURCE_H
