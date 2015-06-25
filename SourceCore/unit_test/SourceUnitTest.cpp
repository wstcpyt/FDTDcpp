//
// Created by yutong pang on 6/23/15.
//

#include <gmock/gmock.h>
#include "SourceCore/HardSource.h"
#include <vector>
using namespace testing;

class SourceType: public Test{
public:
    HardSource hardSource;
};

TEST_F(SourceType, HardSource){
    std::vector<double> EGrid_z(200, 0.0);
    ASSERT_THAT(hardSource.addSource(30, EGrid_z), 1);
}

