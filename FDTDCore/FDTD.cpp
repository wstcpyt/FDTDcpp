//
// Created by yutong pang on 6/24/15.
//

#include "FDTD.h"
#include "FieldCore/EMField.h"
#include "SourceCore/HardSource.h"

void FDTD::runSimulation(){
    EMField field(200);
    HardSource hardSource;
    for (time = 0; time < MAXTIME; time++){
        field.updateEGrid(EGrid_Z, HGrid_y);
        field.updateHGrid(EGrid_Z, HGrid_y);
        hardSource.addSource(time, EGrid_Z);
        printf("%g\n", EGrid_Z[50]);
    }
}

FDTD::FDTD() {
    EGrid_Z.assign(SIZE, 0.0);
    HGrid_y.assign(SIZE, 0.0);
}
