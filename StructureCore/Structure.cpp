//
// Created by yutong pang on 6/27/15.
//

#include "Structure.h"
Structure::Structure() {
    permittivity.assign(STRUCTURE_SIZE, 0.0);
    loss.assign(STRUCTURE_SIZE, 0.0);
    int gridpoint;
    for (gridpoint = 0; gridpoint < STRUCTURE_SIZE; gridpoint++)
    {
        if (gridpoint < 100){
            permittivity[gridpoint] = 1.0;
            loss[gridpoint] = 0.0;
        }
        else if (gridpoint < 180) {
            permittivity[gridpoint] = 9.0;
            loss[gridpoint] = 0.0;
        }
        else{
            permittivity[gridpoint] = 9.0;
            loss[gridpoint] = 0.02;
        }
    }
}