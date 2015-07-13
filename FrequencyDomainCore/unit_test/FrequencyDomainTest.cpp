//
// Created by yutong pang on 7/10/15.
//
#include <iostream>
#include <gmock/gmock.h>
#include "FrequencyDomainCore/FrequencyDomain.h"
#include <vector>
#include "constant.h"
using namespace testing;
using std::vector;
using std::cerr;
class FrequencyDomainTEST: public Test{
public:
    size_t timedomainsize {8};
    vector<double> timedomainarray{0.0, 1.0, 2.0, 3.0, 2.0, 1.0, 0.0, 0.0};
    FrequencyDomain frequencyDomain = FrequencyDomain::FrequencyDomain(timedomainarray);
};

TEST_F(FrequencyDomainTEST, classConstructor){
    ASSERT_THAT(frequencyDomain.getTimedomainarray().size(), timedomainsize);
    ASSERT_THAT(frequencyDomain.getIntensity().size(), timedomainsize);
    ASSERT_THAT(frequencyDomain.getComplexpvector().size(), timedomainsize * 2 );
}

TEST_F(FrequencyDomainTEST, fftreal){
    auto intensity = frequencyDomain.fftrealToIntensity();
    ASSERT_THAT(intensity[2],intensity[6]);
    ASSERT_THAT(intensity[3],intensity[5]);
}