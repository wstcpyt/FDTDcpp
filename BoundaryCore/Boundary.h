//
// Created by yutong pang on 6/26/15.
//

#ifndef FDTDCPP_BOUNDARY_H
#define FDTDCPP_BOUNDARY_H
#include "constant.h"
#include <vector>
#include "StructureCore/Structure.h"
#include "FieldCore/EMField.h"
#include "SourceCore/RickerWaveletSource.h"

class Boundary {
    Structure structure;
    double ezOldLeft{0.0};
    double ezOldRight{0.0};
    RickerWaveletSource rickerWaveletSource;
public:
    friend class BoundaryTest;
    Boundary();
    ~Boundary(){};
    void addMagteticABC(EMField& emField) const;
    void addElectricABC(EMField& emField) const;
    void addMagneticTFSF(const int& time, const int& sourcelocation, EMField& emField) const;
    void addElectricTFSF(const int& time, const int& sourcelocation, EMField& emField) const;
    void addElectricFirstABC(EMField& emField);


private:
    double updateCpattern(const double parameter) const;
};
#endif //FDTDCPP_BOUNDARY_H