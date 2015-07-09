//
// Created by yutong pang on 7/8/15.
//

#ifndef FDTDCPP_EMFIELDABSTRACT_H
#define FDTDCPP_EMFIELDABSTRACT_H
#include <vector>
#include "StructureCore/Structure.h"
#include <math.h>
class EMFieldabstract
{
protected:
    double Cdtds;
    Structure structure;
    std::vector<double> Ez;
    std::vector<double> Hy;
    const double getCeze(const int gridpoint) const;
    const double getCezh(const int gridpoint) const;
    const double getChyh(const int gridpoint) const;
    const double getChye(const int gridpoint) const;
public:
    friend class Boundary;
    friend class RickerWaveletSource;
    EMFieldabstract(const double Cdtds);
    virtual ~EMFieldabstract(){};
    virtual void updateElectricField()=0;
    virtual void updateMagneticField()=0;

    const std::vector<double> &getEz() const {
        return Ez;
    }

    virtual const std::vector<double> &getHy() const {
        return Hy;
    }
};
#endif //FDTDCPP_EMFIELDABSTRACT_H
