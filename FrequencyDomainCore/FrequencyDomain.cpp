//
// Created by yutong pang on 7/10/15.
//

#include "FrequencyDomain.h"
#include <gsl/gsl_fft_real.h>
#include <gsl/gsl_fft_halfcomplex.h>
#include <stdio.h>
#include <math.h>

using std::vector;
using std::unique_ptr;

FrequencyDomain::FrequencyDomain(const vector<double>& timedomainarray): timedomainarray{timedomainarray} {
    timedomainsize = timedomainarray.size();
    intensity.assign(timedomainsize, 0.0);
    complexpvector.assign(timedomainsize * 2, 0.0);
}


void FrequencyDomain::fftreal() {
    fft_real_radix2_transform();
    fft_halfcomplex_radix2_unpack();
    transferComplexToIntensity();
    drawfrequencydomaindata();
}



void FrequencyDomain::drawfrequencydomaindata(){
    lineChart.drawchart(intensity, 1);
}

void FrequencyDomain::drawtimedomaindata(){
    lineChart.drawchart(timedomainarray, 1);
}

void FrequencyDomain::fft_real_radix2_transform() {
    gsl_fft_real_radix2_transform(complex_half, 1, timedomainsize);
}

void FrequencyDomain::fft_halfcomplex_radix2_unpack() {
    double* complex_p = &complexpvector[0];
    gsl_fft_halfcomplex_radix2_unpack(complex_half, complex_p, 1, timedomainsize);
}

void FrequencyDomain::transferComplexToIntensity() {
    double* complex_p = &complexpvector[0];
    for (int i=0; i< timedomainsize; i++){
        double real = complex_p[2 * i];
        double image = complex_p[2 * i + 1];
        double intensityvalue = sqrt(pow(real, 2.0) + pow(image, 2.0));
        intensity[i] = intensityvalue;
    }
}