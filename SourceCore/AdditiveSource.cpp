//
// Created by yutong pang on 6/26/15.
//

#include "AdditiveSource.h"
#include <math.h>

void AdditiveSource::addSource(const int& time, std::vector<double>& EGrid_z, const int& sourcePosition) const{
    EGrid_z[sourcePosition] += exp(-(time - 30.) * (time -30.) / 100.);
}