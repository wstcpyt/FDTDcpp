//
// Created by yutong pang on 6/24/15.
//

#include "EMField.h"
EMField::EMField(int size): gridsize(size){
    EGrid.assign(size, 0.0);
    MGrid.assign(size, 0.0);
}
