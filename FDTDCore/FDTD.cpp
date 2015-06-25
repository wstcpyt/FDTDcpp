//
// Created by yutong pang on 6/24/15.
//

#include "FDTD.h"
#include "FieldCore/EMField.h"

void FDTD::runSimulation(){
    for (time = 0; time < MAXTIME; time++){
        EMField field(200);
        field.updateHGrid();
        field.updateEGrid();
    }
}