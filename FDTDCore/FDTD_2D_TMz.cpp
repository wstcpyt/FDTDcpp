//
// Created by yutong pang on 6/29/15.
//

#include "FDTD_2D_TMz.h"
#include "VisualCore/ColorMap.h"
#include "VisualCore/Gifanimate.h"
FDTD2DTMz::FDTD2DTMz() {
    waterFallVector.assign(STRUCTURE_SIZE_X, std::vector<double>(STRUCTURE_SIZE_Y, 0.0));
}

void FDTD2DTMz::runSimulation() {
    Gifanimate gifanimate;
    ColorMap colorMap;
    int time;
    int xgridpoint;
    int ygridpoint;
    for (time = 0; time < MAXTIME; time++){
        emField2DTMz.updateMagneticField();
        emField2DTMz.updateElectricField();
        rickerWaveletSource.addRickerWaveletSource(STRUCTURE_SIZE_X / 2, STRUCTURE_SIZE_Y / 2, time, 0.0, emField2DTMz);
        if (time == 30){
            for (ygridpoint = 0; ygridpoint < STRUCTURE_SIZE_Y; ygridpoint++){
                    for (xgridpoint = 0; xgridpoint < STRUCTURE_SIZE_X; xgridpoint++){
                    waterFallVector[xgridpoint][ygridpoint] = emField2DTMz.get2DEz()[xgridpoint][ygridpoint];
                }
            }
            colorMap.drawchart(waterFallVector, time/10);
        }
    }
}