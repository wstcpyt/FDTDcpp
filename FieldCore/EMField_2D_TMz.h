//
// Created by yutong pang on 6/28/15.
//

#ifndef FDTDCPP_EMFIELD_2D_TMZ_H
#define FDTDCPP_EMFIELD_2D_TMZ_H

#include <vector>
#include "math.h"
#include "constant.h"
class EMField2DTMz {
    const double Cdtds {1.0 / sqrt(2.0)};
public:
    EMField2DTMz(){};
    ~EMField2DTMz() { };

    void updateMagneticField(std::vector<std::vector<double>> &Ez, std::vector<std::vector<double>> &Hx,
                             std::vector<std::vector<double >> &Hy) const;

    void updateElectricField(std::vector<std::vector<double>> &Ez, std::vector<std::vector<double>> &Hx,
                             std::vector<std::vector<double >> &Hy) const;

private:
    double getChxh() const;
    double getChxe() const;
    double getChyh() const;
    double getChye() const;
    double getCezh() const;
    double getCeze() const;
};

#endif //FDTDCPP_EMFIELD_2D_TMZ_H
