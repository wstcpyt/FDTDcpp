//
// Created by yutong pang on 6/24/15.
//

#include "HardSource.h"
#include <math.h>

double HardSource::addSource(const int& time) const {
    return exp(-(time - 30.) * (time - 30.) / 100.);
}
