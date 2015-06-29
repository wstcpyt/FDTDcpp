//
// Created by yutong pang on 6/24/15.
//

#include "FDTD.h"
#include "SourceCore/AdditiveSource.h"
#include "VisualCore/ColorMap.h"
FDTD::FDTD() {
    Ez.assign(STRUCTURE_SIZE, 0.0);
    Hy.assign(STRUCTURE_SIZE - 1, 0.0);
    lineChartVector.assign(MAXTIME, 0.0);
    waterFallVector.assign(STRUCTURE_SIZE, std::vector<double>(MAXTIME));
}


void FDTD::runSimulation(){
    ColorMap colorMap;
    for (time = 0; time < MAXTIME; time++){
        updateMagneticPart(time);
        boundary.addMagneticTFSF(time, SOURCEPOSITION, Hy);
        boundary.addElectricTFSF(time, SOURCEPOSITION, Ez);
        updateElectricPart(time);
        int gridpoint;
        for (gridpoint=0; gridpoint < STRUCTURE_SIZE; gridpoint++){
            waterFallVector[gridpoint][time] = Ez[gridpoint];
        }
        lineChartVector[time] = Ez[50];
    }
    colorMap.drawchart(waterFallVector);
}

void FDTD::updateMagneticPart(const int &time) {
    emField.updateMagneticField(Ez, Hy);
}

void FDTD::updateElectricPart(const int &time) {
    emField.updateElectricField(Ez, Hy);
    boundary.addElectricFirstABC(Ez);
}
