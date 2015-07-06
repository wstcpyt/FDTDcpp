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
    std::vector<double> permittivity;
    std::vector<double> loss;
    const double getElectricUpdateC_E(const int gridpoint) const;
    const double getElectricUpdateC_H(const int gridpoint) const;
    const double getMagneticUpdateC_E(const int gridpoint) const;
    const double getMagneticUpdateC_H(const int gridpoint) const;
public:
    EMField();
    ~EMField(){};
    virtual void updateElectricField(std::vector<double> &Ez, std::vector<double> &Hy) const;
    virtual void updateMagneticField(std::vector<double> &Ez, std::vector<double> &Hy) const;
    const std::vector<double> &getPermittivity() const {
        return permittivity;
    }
    const std::vector<double> &getLoss() const {
        return loss;
    }
};
#endif //FDTDCPP_FIELD_H
