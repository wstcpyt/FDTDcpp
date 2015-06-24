#include <math.h>
#include <stdio.h>
#include "SourceCore/Source.h"
#include <string>
#define SIZE 200

int main() {
    double ez[SIZE] = {0.}, hy[SIZE] = {0.}, imp0 = 377.0;
    int qTime, maxTime = 250, mm;
    Source source;
    for (qTime = 0; qTime < maxTime; qTime++) {
        /* update magnetic field*/
        for (mm=0; mm < SIZE - 1; mm++){
            hy[mm] = hy[mm] + (ez[mm + 1] - ez[mm]) / imp0;
        }
        /* update electric field*/
        for (mm = 1; mm < SIZE; mm++){
            ez[mm] = ez[mm] + (hy[mm] - hy[mm - 1])*imp0;
        }
        /* hardwire a source node */
        ez[0] = source.addSource(qTime, "hardsource");
        printf("%g\n", ez[50]);

    }
    return 0;
}