//
// Created by yutong pang on 6/29/15.
//

#include "FDTD_2D_TMz.h"
#include "VisualCore/ColorMap.h"
FDTD2DTMz::FDTD2DTMz() {
    Ez.assign(STRUCTURE_SIZE_X, std::vector<double> (STRUCTURE_SIZE_Y, 0.0));
    Hx.assign(STRUCTURE_SIZE_X, std::vector<double> (STRUCTURE_SIZE_Y - 1, 0.0));
    Hy.assign(STRUCTURE_SIZE_X - 1, std::vector<double> (STRUCTURE_SIZE_Y, 0.0));
    waterFallVector.assign(STRUCTURE_SIZE_X, std::vector<double>(STRUCTURE_SIZE_Y, 0.0));

}

void FDTD2DTMz::runSimulation() {
    ColorMap colorMap;
    int time;
    int xgridpoint;
    int ygridpoint;
    for (time = 0; time < MAXTIME; time++){
        emField2DTMz.updateMagneticField(Ez, Hx, Hy);
        emField2DTMz.updateElectricField(Ez, Hx, Hy);
        rickerWaveletSource.addRickerWaveletSource(Ez, STRUCTURE_SIZE_X / 2, STRUCTURE_SIZE_Y / 2, time, 0.0);
        if (time == 110){
            for (ygridpoint = 0; ygridpoint < STRUCTURE_SIZE_Y; ygridpoint++){
                    for (xgridpoint = 0; xgridpoint < STRUCTURE_SIZE_X; xgridpoint++){
                    waterFallVector[xgridpoint][ygridpoint] = Ez[xgridpoint][ygridpoint];
                }
            }
        }
    }
    colorMap.drawchart(waterFallVector);

}