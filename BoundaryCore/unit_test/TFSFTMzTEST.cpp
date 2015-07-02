//
// Created by yutong pang on 7/1/15.
//

#include <gmock/gmock.h>
#include "BoundaryCore/TFSFTMz.h"
#include <vector>
using namespace testing;
class TFSFTMzTEST: public Test{
public:
    TFSFTMz tfsftMz = TFSFTMz::TFSFTMz(5, 5, 95, 75 );
};

TEST_F(TFSFTMzTEST, TFSFTMZconstructor){
    ASSERT_THAT(tfsftMz.getFirstX(), 5);
    ASSERT_THAT(tfsftMz.getFirstY(), 5);
    ASSERT_THAT(tfsftMz.getLastX(), 95);
    ASSERT_THAT(tfsftMz.getLastY(), 75);
}

TEST_F(TFSFTMzTEST, addTFSFBounday){
    std::vector<std::vector<double>> Ez(100, std::vector<double>(100));
    std::vector<std::vector<double>> Hx(100, std::vector<double>(100));
    std::vector<std::vector<double>> Hy(100, std::vector<double>(100));
    int time = 1;
    tfsftMz.addBounday(Ez, Hx, Hy, time);
}