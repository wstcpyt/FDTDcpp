//
// Created by yutong pang on 7/10/15.
//

#include <gmock/gmock.h>
#include "FrequencyDomainCore/FrequencyDomain.h"
#include <vector>
using namespace testing;
using std::vector;
class FrequencyDomainTEST: public Test{
public:
    vector<vector<double>> timearray {4,{4,0.0}};
    FrequencyDomain frequencyDomain = FrequencyDomain::FrequencyDomain(timearray);

};

TEST_F(FrequencyDomainTEST, classConstructor){
    frequencyDomain.dotransfer();
}