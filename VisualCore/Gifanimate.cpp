//
// Created by yutong pang on 7/1/15.
//

#include "Gifanimate.h"
#include <stdio.h>
void Gifanimate::drawchart() {
    FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
    fprintf(gnuplotPipe, "reset\n");//Send commands to gnuplot one by one.
    fprintf(gnuplotPipe, "set term gif animate \n");
    fprintf(gnuplotPipe, "set output \"/Users/yutongpang/animate.gif\" \n");
    fprintf(gnuplotPipe, "n=24  \n");
    fprintf(gnuplotPipe, "dt=2*pi/n\n");
    fprintf(gnuplotPipe, "set xrange [0:4*pi]\n");
    fprintf(gnuplotPipe, "set yrange [-1:1]\n");
    fprintf(gnuplotPipe, "do for [i=0:n]{\n");
    fprintf(gnuplotPipe, "plot sin(x+i*dt)/(1. + i/12.) w l lw 1.5 title sprintf(\"t=%i\",i)\n", 1);
    fprintf(gnuplotPipe, "}\n");
    fprintf(gnuplotPipe, "set output \n");
    pclose(gnuplotPipe);
}