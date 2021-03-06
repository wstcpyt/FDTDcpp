//
// Created by yutong pang on 6/24/15.
//

#ifndef FDTDCPP_FDTD_H
#define FDTDCPP_FDTD_H

#include <vector>
#include "BoundaryCore/Boundary.h"
#include "FieldCore/EMField.h"
#include "constant.h"
#define SOURCEPOSITION 50

class FDTD{
    int time;
    Structure structure = Structure::Structure(2, 4);
    EMField emField = EMField::EMField(structure);
    std::vector<double> lineChartVector;
    std::vector<std::vector<double>> waterFallVector;
    Boundary boundary;
public:
    FDTD();
    ~FDTD(){};
    void runSimulation();
    const std::vector<double> &getlineChartVector() const {
        return lineChartVector;
    }
    const std::vector<std::vector<double>> &getwaterFallVector() const {
        return waterFallVector;
    }

private:
    void updateMagneticPart(const int& time);
    void updateElectricPart(const int& time);
};
#endif //FDTDCPP_FDTD_H
