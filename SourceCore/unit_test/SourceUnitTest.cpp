//
// Created by yutong pang on 6/23/15.
//

#include <gmock/gmock.h>
#include "SourceCore/HardSource.h"
#include "SourceCore/AdditiveSource.h"
#include "SourceCore/RickerWaveletSource.h"
#include <vector>
using namespace testing;

class SourceType: public Test{
public:
    HardSource hardSource;
    AdditiveSource additiveSource;
    RickerWaveletSource rickerWaveletSource;
};

TEST_F(SourceType, HardSource){
    std::vector<double> Ez(200, 0.0);
    ASSERT_THAT(hardSource.addSource(30, Ez), 1);
}

TEST_F(SourceType, AdditiveSource){
    std::vector<double> Ez(200, 0.0);
    additiveSource.addSource(30, Ez, 50);
    ASSERT_THAT(Ez[50], 1);
}

TEST_F(SourceType, rickerWaveletSource_1D){
    double returnvalue = rickerWaveletSource.addRickerWaveletSource(10, 0);
}