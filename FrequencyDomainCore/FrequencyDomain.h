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
    const vector<double> fftrealToIntensity();
    void drawtimedomaindata();
    void drawfrequencydomaindata();

    const vector<double> &getIntensity() const {
        return intensity;
    }

    const vector<double> &getTimedomainarray() const {
        return timedomainarray;
    }

    const vector<double> &getComplexpvector() const {
        return complexpvector;
    }

private:
    void fft_real_radix2_transform();
    void fft_halfcomplex_radix2_unpack();
    void transferComplexToIntensity();
    double getintensity(const double real,const double imag) const;

};

#endif //FDTDCPP_FREQUENCYDOMAIN_H
