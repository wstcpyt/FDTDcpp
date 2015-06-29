//
// Created by yutong pang on 6/24/15.
//

#include <gmock/gmock.h>
#include "FieldCore/EMField.h"
#include "FieldCore/EMField_2D_TMz.h"
#include "constant.h"
using namespace testing;
#define SIZE 200

class FieldTest: public Test{
public:
    EMField emField = EMField::EMField();
    EMField2DTMz emField2DTMz;
};

TEST_F(FieldTest, EMfieldUpdateElectricField){
    std::vector<double> Ez(200, 0.0);
    std::vector<double> Hy(200, 0.0);
    Hy[1] = 1.0;
    emField.updateElectricField(Ez, Hy);
    ASSERT_THAT(Ez[1], IMP0);
}

TEST_F(FieldTest, EMfieldUpdateMagneticField){
    std::vector<double> Ez(200, 0.0);
    std::vector<double> Hy(200, 0.0);
    Ez[1] = 1.0;
    emField.updateMagneticField(Ez, Hy);
    ASSERT_THAT(Hy[0], 1 / IMP0);
}

TEST_F(FieldTest, EMfieldGetPermittivity){
    ASSERT_THAT(emField.getPermittivity().size(), STRUCTURE_SIZE);
}

TEST_F(FieldTest, EMfieldGetLoss){
    ASSERT_THAT(emField.getLoss().size(), STRUCTURE_SIZE);
}

TEST_F(FieldTest, EMField2DTMzUpdateMagneticField){
    std::vector<std::vector<double>> Ez(200, std::vector<double>(200, 0.0));
    std::vector<std::vector<double>> Hx(200, std::vector<double>(200, 0.0));
    std::vector<std::vector<double>> Hy(200, std::vector<double>(200, 0.0));
    emField2DTMz.updateMagneticField(Ez, Hx, Hy);
}

TEST_F(FieldTest, EMField2DTMzUpdateElectricField){
    std::vector<std::vector<double>> Ez(200, std::vector<double>(200, 0.0));
    std::vector<std::vector<double>> Hx(200, std::vector<double>(200, 0.0));
    std::vector<std::vector<double>> Hy(200, std::vector<double>(200, 0.0));
    emField2DTMz.updateElectricField(Ez, Hx, Hy);
}
