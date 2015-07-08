//
// Created by yutong pang on 6/24/15.
//

#include "FDTD.h"
#include "VisualCore/ColorMap.h"
#include <iostream>
#include <CommonCore/Time.h>

FDTD::FDTD() {
    lineChartVector.assign(STRUCTURE_SIZE, 0.0);
    waterFallVector.assign(STRUCTURE_SIZE, std::vector<double>(MAXTIME));
}


void FDTD::runSimulation(){
    ColorMap colorMap;
    //LineChart lineChart;
    for (time = 0; time < MAXTIME; time++){
        updateMagneticPart(time);
        boundary.addMagneticTFSF(time, SOURCEPOSITION, emField);
        boundary.addElectricTFSF(time, SOURCEPOSITION, emField);
        double start = get_time();
        updateElectricPart(time);
        std::cerr << get_time() - start << std::endl;
        int gridpoint;
        for (gridpoint=0; gridpoint < STRUCTURE_SIZE; gridpoint++){
            waterFallVector[gridpoint][time] = emField.getEz()[gridpoint];
        }
    }
    colorMap.drawchart(waterFallVector, 1);
}

void FDTD::updateMagneticPart(const int &time) {
    emField.updateMagneticField();
}

void FDTD::updateElectricPart(const int &time) {
    emField.updateElectricField();
    boundary.addElectricFirstABC(emField);
}
