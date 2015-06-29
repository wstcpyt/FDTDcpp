//
// Created by yutong pang on 6/26/15.
//

#include <gmock/gmock.h>
#include <BoundaryCore/Boundary.h>
using namespace testing;

class BoundaryTest: public Test{
public:
    Boundary boundary;
};

TEST_F(BoundaryTest, addMagteticABCBoundaryCondition){
    std::vector<double> HGrid_y =  {1, 2, 3, 4 ,5};
    boundary.addMagteticABC(HGrid_y);
    ASSERT_THAT(HGrid_y[4], 4);
}
TEST_F(BoundaryTest, addElectricABCBoundaryCondition){
    std::vector<double> EGrid_z =  {1, 2, 3, 4 ,5};
    boundary.addElectricABC(EGrid_z);
    ASSERT_THAT(EGrid_z[0], 2);
}

TEST_F(BoundaryTest, addMagneticTFSFcorrection){
    std::vector<double> HGrid_y =  {1, 2, 3, 4 ,5};
    boundary.addMagneticTFSF(30, 2, HGrid_y);
    ASSERT_THAT(HGrid_y[1], 2 - 1/IMP0);
}

TEST_F(BoundaryTest, addElectricTFSFcorrection){
    std::vector<double> EGrid_z =  {1, 2, 3, 4 ,5};
    boundary.addElectricTFSF(29, 2, EGrid_z);
    ASSERT_THAT(EGrid_z[2], 3 + 1);
}

TEST_F(BoundaryTest, addELectricFirstABC){
    std::vector<double> EGrid_z =  {1, 2, 3, 4 ,5};
    boundary.addElectricFirstABC(EGrid_z);
}

TEST_F(BoundaryTest, GetPermittivity){
    ASSERT_THAT(boundary.getPermittivity().size(), STRUCTURE_SIZE);
}