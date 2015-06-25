//
// Created by yutong pang on 6/24/15.
//

#include <gmock/gmock.h>
#include "FieldCore/EMField.h"
using namespace testing;
#define SIZE 200

class FieldTest: public Test{
public:
    EMField emField = EMField::EMField(SIZE);
};

TEST_F(FieldTest, EMfieldConstructGridSize){
    ASSERT_THAT(emField.getGridsize(), 200);
}

TEST_F(FieldTest, UpdateEGrid){
    std::vector<double> EGrid_z(200, 0.0);
    std::vector<double> HGrid_y(200, 0.0);
    HGrid_y[1] = 1.0;
    emField.updateEGrid(EGrid_z, HGrid_y);
    ASSERT_THAT(EGrid_z[1], 377.0);
}

TEST_F(FieldTest, UpdateHGrid){
    std::vector<double> EGrid_z(200, 0.0);
    std::vector<double> HGrid_y(200, 0.0);
    EGrid_z[1] = 1.0;
    emField.updateHGrid(EGrid_z, HGrid_y);
    ASSERT_THAT(HGrid_y[0], 1 / 377.0);
}