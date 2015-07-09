//
// Created by yutong pang on 6/24/15.
//

#include <gmock/gmock.h>
#include "FieldCore/EMField.h"
#include "FieldCore/EMField_2D_TMz.h"
using namespace testing;
#define SIZE 200

class FieldTest: public Test{
public:
    EMField emField = EMField::EMField();
    EMField2DTMz emField2DTMz;
};

TEST_F(FieldTest, EMfieldUpdateElectricField){
    emField.updateElectricField();
}

TEST_F(FieldTest, EMfieldUpdateMagneticField){
    emField.updateMagneticField();
}



