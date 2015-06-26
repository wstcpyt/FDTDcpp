//
// Created by yutong pang on 6/24/15.
//

#include "FDTD.h"
#include "FieldCore/EMField.h"
#include "SourceCore/AdditiveSource.h"
#include "VisualCore/ColorMap.h"
void FDTD::runSimulation(){
    EMField field(200);
    AdditiveSource additiveSource;
    ColorMap colorMap;
    for (time = 0; time < MAXTIME; time++){
        field.updateEGrid(EGrid_Z, HGrid_y);
        field.updateHGrid(EGrid_Z, HGrid_y);
        additiveSource.addSource(time, EGrid_Z, SOURCEPOSITION);
        int gridpoint;
        for (gridpoint=0; gridpoint < SIZE; gridpoint++){
            waterFallVector[time][gridpoint] = EGrid_Z[gridpoint];
        }
        lineChartVector[time] = EGrid_Z[50];
    }
    colorMap.drawchart(waterFallVector);
}

FDTD::FDTD() {
    EGrid_Z.assign(SIZE, 0.0);
    HGrid_y.assign(SIZE, 0.0);
    lineChartVector.assign(MAXTIME, 0.0);
    waterFallVector.assign(MAXTIME, std::vector<double>(SIZE));
}
