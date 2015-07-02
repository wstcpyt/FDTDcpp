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

TEST_F(FDTDTest, FDTDsimulationhasEGrid){
    ASSERT_THAT(fdtd.getEz().size(), STRUCTURE_SIZE);
}

TEST_F(FDTDTest, FDTDsimulatiohasHGrid){
    ASSERT_THAT(fdtd.getHy().size(), STRUCTURE_SIZE - 1);
}

TEST_F(FDTDTest, FDTDrunsimulation){
    fdtd.runSimulation();
}

TEST_F(FDTDTest, FDTDLineChartVector){
    ASSERT_THAT(fdtd.getlineChartVector().size(), STRUCTURE_SIZE);
}


TEST_F(FDTDTest, FDTD2DTMzsimulationhasEGrid){
    ASSERT_THAT(fdtd2DTMz.getEz().size(), STRUCTURE_SIZE_X);
    ASSERT_THAT(fdtd2DTMz.getEz()[0].size(), STRUCTURE_SIZE_Y);
}

TEST_F(FDTDTest, FDTD2DTMzsimulationhasHGrid){
    ASSERT_THAT(fdtd2DTMz.getHx().size(), STRUCTURE_SIZE_X);
    ASSERT_THAT(fdtd2DTMz.getHx()[0].size(), STRUCTURE_SIZE_Y - 1);
    ASSERT_THAT(fdtd2DTMz.getHy().size(), STRUCTURE_SIZE_X -1);
    ASSERT_THAT(fdtd2DTMz.getHy()[0].size(), STRUCTURE_SIZE_Y);
}

TEST_F(FDTDTest, FDTD2DTMzRunsimulation){
    fdtd2DTMz.runSimulation();
}