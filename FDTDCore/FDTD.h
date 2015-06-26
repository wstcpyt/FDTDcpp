//
// Created by yutong pang on 6/24/15.
//

#ifndef FDTDCPP_FDTD_H
#define FDTDCPP_FDTD_H

#include <vector>
#define SIZE 200
#define MAXTIME 250

class FDTD{
    int time;
    std::vector<double> EGrid_Z;
    std::vector<double> HGrid_y;
    std::vector<double> lineChartVector;
public:
    FDTD();
    ~FDTD(){};
    void runSimulation();
    const std::vector<double> &getEGrid_z() const {
        return EGrid_Z;
    }
    const std::vector<double> &getHGrid_y() const {
        return HGrid_y;
    }
    const std::vector<double> &getlineChartVector() const {
        return lineChartVector;
    }

};
#endif //FDTDCPP_FDTD_H
