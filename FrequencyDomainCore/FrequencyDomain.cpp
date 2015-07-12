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

    double *complex_halfp = new double[timesize];
    double *complexp = new double[timesize*2];
    gsl_complex_packed_array complex_p = complexp;

    for (int i =0; i< timesize; i++){
        complex_halfp[i] = fdtdtimearray[30][i];
    }
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



    delete[](complexp);
    delete[](complex_halfp);
    gsl_fft_real_radix2_transform(data, 1, 8);
    for (int i = 0; i < 8; i++){
        printf("%e\n", data[i]);
    }

    printf("\n");
    double x[8*2];
    gsl_complex_packed_array complexarray = x;
    gsl_fft_halfcomplex_radix2_unpack(data, complexarray, 1, 8);
    for (int i = 0; i< 16; i++){
        printf("%e\n", complexarray[i]);
    }

    vector<double> testintensity (8, 0.0);
    for (int i = 0; i < 8; i++){
        double real = complexarray[2 * i];
        double image =  complexarray[2 * i + 1];
        testintensity[i] = sqrt(real * real + image * image);
    }
    //lineChart.drawchart(testintensity, 3);
}

