//
// Created by yutong pang on 6/24/15.
//

#ifndef FDTDCPP_HARDSOURCE_H
#define FDTDCPP_HARDSOURCE_H

#include <vector>
#include "Source.h"
class HardSource: Source
{
public:
    double addSource(const int& time, std::vector<double>& EGrid_z) const ;
};
#endif //FDTDCPP_HARDSOURCE_H
