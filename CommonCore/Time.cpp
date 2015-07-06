//
// Created by yutong pang on 7/3/15.
//

#include "Time.h"
#include <sys/time.h>
double get_time() {
    timeval tim;
    gettimeofday(&tim, NULL);
    double t = tim.tv_sec + (tim.tv_usec / 1000000.0);
    return t;
}