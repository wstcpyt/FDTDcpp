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

TEST_F(FieldTest, EMfieldConstructEandMGridinRightSIZE){
    ASSERT_THAT(emField.getEGrid().size(), 200);
    ASSERT_THAT(emField.getMGrid().size(), 200);
}