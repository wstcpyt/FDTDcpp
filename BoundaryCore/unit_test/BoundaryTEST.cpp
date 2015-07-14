//
// Created by yutong pang on 6/26/15.
//

#include <gmock/gmock.h>
#include <BoundaryCore/Boundary.h>
using namespace testing;

class BoundaryTest: public Test{
public:
    Boundary boundary;
    double testupdateCpattern(const double parameter){
        return boundary.updateCpattern(parameter);
    }
    Structure structure;
    EMField emField = EMField::EMField(structure);

};

TEST_F(BoundaryTest, addMagteticABCBoundaryCondition){
    boundary.addMagteticABC(emField);
}
TEST_F(BoundaryTest, addElectricABCBoundaryCondition){
    boundary.addElectricABC(emField);
}

TEST_F(BoundaryTest, addMagneticTFSFcorrection){
    boundary.addMagneticTFSF(30, 2, emField);
    //ASSERT_THAT(emField.getHy()[1], -1/IMP0);
}

TEST_F(BoundaryTest, addElectricTFSFcorrection){
    boundary.addElectricTFSF(29, 2, emField);
    //ASSERT_THAT(emField.getEz()[2], 1);
}

TEST_F(BoundaryTest, addELectricFirstABC){
    boundary.addElectricFirstABC(emField);
}

TEST_F(BoundaryTest, updateCpattern){
    ASSERT_THAT(BoundaryTest::testupdateCpattern(1), 0);
    ASSERT_THAT(BoundaryTest::testupdateCpattern(3), 0.5);
};
