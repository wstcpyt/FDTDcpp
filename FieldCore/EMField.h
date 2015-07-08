//
// Created by yutong pang on 6/24/15.
//

#ifndef FDTDCPP_FIELD_H
#define FDTDCPP_FIELD_H
#include <vector>
#include "StructureCore/Structure.h"
class EMField
{
protected:
    Structure structure;
    std::vector<double> Ez;
    std::vector<double> Hy;
    const double getCeze(const int gridpoint) const;
    const double getCezh(const int gridpoint) const;
    const double getChyh(const int gridpoint) const;
    const double getChye(const int gridpoint) const;
public:
    EMField();
    ~EMField(){};
    friend class Boundary;
    virtual void updateElectricField();
    virtual void updateMagneticField();

    const std::vector<double> &getEz() const {
        return Ez;
    }

    const std::vector<double> &getHy() const {
        return Hy;
    }
};
#endif //FDTDCPP_FIELD_H
