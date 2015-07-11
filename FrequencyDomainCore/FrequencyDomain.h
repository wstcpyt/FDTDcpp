//
// Created by yutong pang on 7/10/15.
//

#ifndef FDTDCPP_FREQUENCYDOMAIN_H
#define FDTDCPP_FREQUENCYDOMAIN_H

#include <vector>
using std::vector;
class FrequencyDomain {
    vector<vector<double>> fdtdtimearray;
public:
    FrequencyDomain( vector<vector<double>> fdtdtimearray);
    virtual ~FrequencyDomain(){};
    double data[2*4] = {0, 1.0 , 0 , 0, 0, 0, 0, 0};
    void dotransfer();

};

#endif //FDTDCPP_FREQUENCYDOMAIN_H
