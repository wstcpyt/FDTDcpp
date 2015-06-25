//
// Created by yutong pang on 6/24/15.
//
#include <gmock/gmock.h>
#include <FDTDCore/FDTD.h>
using namespace testing;

class FDTDTest: public Test{
public:
    FDTD fdtd;
};

TEST_F(FDTDTest, FDTDrunsimulation){
    fdtd.runSimulation();
}