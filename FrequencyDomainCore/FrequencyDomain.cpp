//
// Created by yutong pang on 7/10/15.
//

#include "FrequencyDomain.h"
#include <gsl/gsl_fft_real.h>
#include <gsl/gsl_fft_halfcomplex.h>
#include "VisualCore/LineChart.h"
#include <stdio.h>
#include <math.h>

using std::vector;
using std::unique_ptr;

FrequencyDomain::FrequencyDomain(vector<vector<double>> fdtdtimearray): fdtdtimearray{fdtdtimearray} {
}


void FrequencyDomain::dotransfer() {
    size_t timesize = fdtdtimearray[0].size();
    double* complex_halfp = &fdtdtimearray[30][0];
    vector<double> complexpvector (timesize*2);
    double* complex_p = &complexpvector[0];
    LineChart lineChart;
    lineChart.drawchart(fdtdtimearray[30], 1);
    gsl_fft_real_radix2_transform(complex_halfp, 1, timesize);
    gsl_fft_halfcomplex_radix2_unpack(complex_halfp, complex_p, 1, timesize);
    vector<double> intensity (timesize, 0.0);
    for (int i=0; i< timesize; i++){
        double real = complex_p[2 * i];
        double image = complex_p[2 * i + 1];
        double intensityvalue = sqrt(real * real + image * image);
        intensity[i] = intensityvalue;
    }
    lineChart.drawchart(intensity, 2);
}

