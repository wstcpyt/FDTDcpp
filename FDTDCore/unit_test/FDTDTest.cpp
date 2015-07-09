//
// Created by yutong pang on 6/24/15.
//
#include <gmock/gmock.h>
#include "FDTDCore/FDTD.h"
#include "FDTDCore/FDTD_2D_TMz.h"
using namespace testing;

class FDTDTest: public Test{
public:
    FDTD fdtd;
    FDTD2DTMz fdtd2DTMz;
};


TEST_F(FDTDTest, FDTDrunsimulation){
    fdtd.runSimulation();
}

TEST_F(FDTDTest, FDTDLineChartVector){
    ASSERT_THAT(fdtd.getlineChartVector().size(), STRUCTURE_SIZE);
}

TEST_F(FDTDTest, FDTD2DTMzRunsimulation){
    fdtd2DTMz.runSimulation();
}