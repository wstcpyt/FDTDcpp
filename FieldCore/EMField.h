//
// Created by yutong pang on 6/24/15.
//

#ifndef FDTDCPP_FIELD_H
#define FDTDCPP_FIELD_H
#include <vector>
#include "StructureCore/Structure.h"
#include "EMFieldabstract.h"
class EMField:public EMFieldabstract
{
protected:
    Structure structure;
public:
    EMField();
    virtual ~EMField(){};
    virtual void updateElectricField();
    virtual void updateMagneticField();
};
#endif //FDTDCPP_FIELD_H
