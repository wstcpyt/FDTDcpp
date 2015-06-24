//
// Created by yutong pang on 6/23/15.
//

#include <gmock/gmock.h>
#include "SourceCore/Source.h"
using namespace testing;

class SourceType: public Test{
public:
    Source source;
};

TEST_F(SourceType, HardSource){
    ASSERT_THAT(source.addSource(30, "hardsource"), 1);
}

