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
    EMField emField = EMField::EMField();
    std::vector<double> Ez;
    std::vector<double> Hy;
    std::vector<double> lineChartVector;
    std::vector<std::vector<double>> waterFallVector;
    Boundary boundary;
public:
    FDTD();
    ~FDTD(){};
    void runSimulation();
    const std::vector<double> &getEGrid_z() const {
        return Ez;
    }
    const std::vector<double> &getHGrid_y() const {
        return Hy;
    }
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
