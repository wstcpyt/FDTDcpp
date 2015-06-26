//
// Created by yutong pang on 6/26/15.
//

#ifndef FDTDCPP_ADDITIVESOURCE_H
#define FDTDCPP_ADDITIVESOURCE_H
#include <vector>
#include "Source.h"
class AdditiveSource: public Source
{
public:
    void addSource(const int& time, std::vector<double>& EGrid_z, const int& sourcePosition) const ;
};
#endif //FDTDCPP_ADDITIVESOURCE_H
