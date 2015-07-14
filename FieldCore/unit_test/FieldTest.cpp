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
    Structure structure;
    EMField emField = EMField::EMField(structure);
    EMField2DTMz emField2DTMz = EMField2DTMz::EMField2DTMz(structure);
};


//Test for EMField

TEST_F(FieldTest, EMFieldConstructor){
    double Cdtds1D = emField.getCdtds();
    ASSERT_THAT(Cdtds1D, 1.0);
}

TEST_F(FieldTest, EMFieldupdateElectricField){
    emField.updateElectricField();
}

TEST_F(FieldTest, EMfieldUpdateMagneticField){
    emField.updateMagneticField();
}

//Test for EMField_2D_TMz

TEST_F(FieldTest, EMField2DTMzConstructor){
    double Cdtds2D = emField2DTMz.getCdtds();
    ASSERT_THAT(Cdtds2D, 1.0 / sqrt(2.0));
}

TEST_F(FieldTest, EMField2DTMzupdateElectricField){
    emField2DTMz.updateElectricField();
}

TEST_F(FieldTest, EMField2DTMzUpdateMagneticField){
    emField2DTMz.updateMagneticField();
}





