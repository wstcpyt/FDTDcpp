//
// Created by yutong pang on 7/2/15.
//

#ifndef FDTDCPP_EMFIELD_1D_P_H
#define FDTDCPP_EMFIELD_1D_P_H
#include <vector>
#include "StructureCore/Structure.h"
#include "FieldCore/EMField.h"
class EMField1DP: public EMField
{
public:
    ~EMField1DP(){};
    void updateElectricField(std::vector<double> &Ez, std::vector<double> &Hy);
private:
    void updateElectricFieldthread(std::vector<double>& Ez, std::vector<double>& Hy, const int indexstart, const int indexend);

};
#endif //FDTDCPP_EMFIELD_1D_P_H
