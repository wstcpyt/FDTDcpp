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

TEST_F(FDTDTest, FDTDsimulationhasEGrid){
    ASSERT_THAT(fdtd.getEGrid_z().size(), SIZE);
}

TEST_F(FDTDTest, FDTDsimulatiohasHGrid){
    ASSERT_THAT(fdtd.getHGrid_y().size(), SIZE);
}

TEST_F(FDTDTest, FDTDrunsimulation){
    fdtd.runSimulation();
}

TEST_F(FDTDTest, FDTDLineChartVector){
    ASSERT_THAT(fdtd.getlineChartVector().size(), MAXTIME);
}
