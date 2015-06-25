//
// Created by yutong pang on 6/24/15.
//

#include "HardSource.h"
#include <math.h>

double HardSource::addSource(const int& time, std::vector<double>& EGrid_z) const {
    double constrainValue = exp(-(time - 30.) * (time - 30.) / 100.);
    EGrid_z[0] = constrainValue;
    return constrainValue;
}
