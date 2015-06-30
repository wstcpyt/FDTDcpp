//
// Created by yutong pang on 6/28/15.
//

#ifndef FDTDCPP_RICKERWAVELETSOURCE_H
#define FDTDCPP_RICKERWAVELETSOURCE_H

#include <math.h>
#include <vector>
#include "constant.h"
#define PPW 20
class RickerWaveletSource{
    const double Cdtds {1.0 / sqrt(2.0)};
public:
    RickerWaveletSource(){};
    ~RickerWaveletSource(){};
    void addRickerWaveletSource (std::vector<std::vector<double>>& Ez, const int& positionx, const int& positiony, const double& time, const double& location) const;
};
#endif //FDTDCPP_RICKERWAVELETSOURCE_H
