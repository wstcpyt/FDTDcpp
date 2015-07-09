//
// Created by yutong pang on 6/29/15.
//

#ifndef FDTDCPP_FDTD_2D_TMZ_H
#define FDTDCPP_FDTD_2D_TMZ_H

#include <vector>
#include "constant.h"
#include "FieldCore/EMField_2D_TMz.h"
#include "SourceCore/RickerWaveletSource.h"

class FDTD2DTMz{

    EMField2DTMz emField2DTMz;
    RickerWaveletSource rickerWaveletSource;
    std::vector<std::vector<double>> waterFallVector;
public:
    FDTD2DTMz();
    ~FDTD2DTMz(){};

    void runSimulation();

};
#endif //FDTDCPP_FDTD_2D_TMZ_H
