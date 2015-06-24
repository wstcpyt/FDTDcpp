//
// Created by yutong pang on 6/23/15.
//

#include <gmock/gmock.h>
#include "SourceCore/HardSource.h"
using namespace testing;

class SourceType: public Test{
public:
    HardSource hardSource;
};

TEST_F(SourceType, HardSource){
    ASSERT_THAT(hardSource.addSource(30), 1);
}

