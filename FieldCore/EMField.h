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
    const double getElectricUpdateC_E(const int gridpoint) const;
    const double getElectricUpdateC_H(const int gridpoint) const;
    const double getMagneticUpdateC_E(const int gridpoint) const;
    const double getMagneticUpdateC_H(const int gridpoint) const;
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
