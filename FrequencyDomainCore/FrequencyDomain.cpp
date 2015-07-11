//
// Created by yutong pang on 7/10/15.
//

#include "FrequencyDomain.h"
#include <gsl/gsl_fft_real.h>
#include <gsl/gsl_fft_halfcomplex.h>
#include <stdio.h>

using std::vector;

FrequencyDomain::FrequencyDomain(vector<vector<double>> fdtdtimearray): fdtdtimearray{fdtdtimearray} {
}


void FrequencyDomain::dotransfer() {
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
}

