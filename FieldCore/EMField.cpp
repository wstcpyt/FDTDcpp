//
// Created by yutong pang on 6/24/15.
//

#include "EMField.h"
EMField::EMField(int size): gridsize(size){
}

void EMField::updateEGrid(std::vector<double>& EGrid_z, std::vector<double>& HGrid_y) {
    for(gridpoint = 1; gridpoint < gridsize; gridpoint++){
        EGrid_z[gridpoint] = EGrid_z[gridpoint] + (HGrid_y[gridpoint] - HGrid_y[gridpoint - 1]) * imp0;
    }
}

void EMField::updateHGrid(std::vector<double>& EGrid_z, std::vector<double>& HGrid_y) {
    for(gridpoint = 0; gridpoint < gridsize - 1; gridpoint++){
        HGrid_y[gridpoint] = HGrid_y[gridpoint] + (EGrid_z[gridpoint + 1] - EGrid_z[gridpoint]) / imp0;
    }
}