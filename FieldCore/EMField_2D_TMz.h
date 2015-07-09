//
// Created by yutong pang on 6/28/15.
//

#ifndef FDTDCPP_EMFIELD_2D_TMZ_H
#define FDTDCPP_EMFIELD_2D_TMZ_H

#include <vector>
#include "math.h"
#include "constant.h"
#include "FieldCore/EMField.h"
class EMField2DTMz: public EMFieldabstract {
public:
    friend class RickerWaveletSource;
    EMField2DTMz();

    virtual ~EMField2DTMz() { };

    virtual void updateMagneticField();

    virtual void updateElectricField();

    const std::vector<std::vector<double>> &get2DEz() const {
        return Ez;
    }

private:
    std::vector<std::vector<double>> Ez;
    std::vector<std::vector<double>> Hx;
    std::vector<std::vector<double>> Hy;
    double getChxh(const int gridpoint) const;
    double getChxe(const int gridpoint) const;
};

#endif //FDTDCPP_EMFIELD_2D_TMZ_H
