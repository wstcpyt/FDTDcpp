//
// Created by yutong pang on 7/10/15.
//

#ifndef FDTDCPP_FREQUENCYDOMAIN_H
#define FDTDCPP_FREQUENCYDOMAIN_H

#include <vector>
#include <VisualCore/LineChart.h>

using std::vector;
class FrequencyDomain {
    vector<double> timedomainarray;
    vector<double> complexpvector;
    LineChart lineChart;
    vector<double> intensity;
    size_t timedomainsize;
    double* complex_half = &timedomainarray[0];

public:
    FrequencyDomain(const vector<double>& timedomainarray);
    virtual ~FrequencyDomain(){};
    void fftreal();
    void drawtimedomaindata();
    void drawfrequencydomaindata();
    void fft_real_radix2_transform();
    void fft_halfcomplex_radix2_unpack();
    void transferComplexToIntensity();

private:

};

#endif //FDTDCPP_FREQUENCYDOMAIN_H
