//
// Created by yutong pang on 6/26/15.
//

#ifndef FDTDCPP_BOUNDARY_H
#define FDTDCPP_BOUNDARY_H

#include "constant.h"
#include <vector>
#include "StructureCore/Structure.h"
#include "FieldCore/EMField.h"
class Boundary {
    EMField emField;
    Structure structure;
    std::vector<double> permittivity;
    double ezOldLeft{0.0};
    double ezOldRight{0.0};
public:
    Boundary();
    ~Boundary(){};
    void addMagteticABC(std::vector<double>& HGrid_y) const;
    void addElectricABC(std::vector<double>& EGrid_z) const;
    void addMagneticTFSF(const int& time, const int& sourcelocation, std::vector<double>& HGrid_y) const;
    void addElectricTFSF(const int& time, const int& sourcelocation, std::vector<double>& EGrid_z) const;
    void addElectricFirstABC(std::vector<double>& EGrid_z);

    const std::vector<double> &getPermittivity() const {
        return permittivity;
    }

private:
    double updateCpattern(const double parameter) const;
};
#endif //FDTDCPP_BOUNDARY_H