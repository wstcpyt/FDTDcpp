//
// Created by yutong pang on 6/27/15.
//

#ifndef FDTDCPP_STRUCTURE_H
#define FDTDCPP_STRUCTURE_H
#include <vector>
#include "constant.h"
class Structure{
    std::vector<double> permittivity;
    std::vector<double> loss;
public:
    Structure();
    ~Structure(){};
    friend class EMFieldabstract;
    friend class EMField2DTMz;
    friend class Boundary;
    const std::vector<double> &getPermittivity() const {
        return permittivity;
    }
    const std::vector<double> &getLoss() const {
        return loss;
    }
};
#endif //FDTDCPP_STRUCTURE_H
