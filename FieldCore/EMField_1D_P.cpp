//
// Created by yutong pang on 7/2/15.
//

#include "EMField_1D_P.h"
#include <future>

void EMField1DP::updateElectricField(std::vector<double> &Ez, std::vector<double> &Hy) {
    std::future<void> resutlt1 = std::async([&](){
        updateElectricFieldthread(Ez, Hy, 1, 100);
    });
    std::future<void> resutlt2 = std::async([&](){
        updateElectricFieldthread(Ez, Hy, 100, 199);
    });
}

void EMField1DP::updateElectricFieldthread(std::vector<double> &Ez, std::vector<double> &Hy, const int indexstart, const int indexend) {
    int gridpoint;
    for(gridpoint = indexstart; gridpoint < indexend; gridpoint++){
        double electricUpdateC_E = getCeze(gridpoint);
        double electricUpdateC_H = getCezh(gridpoint);
        Ez[gridpoint] =  electricUpdateC_E * Ez[gridpoint] + electricUpdateC_H * (Hy[gridpoint] - Hy[gridpoint - 1]) ;
    }
}





