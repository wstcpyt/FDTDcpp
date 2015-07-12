//
// Created by yutong pang on 6/26/15.
//
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "LineChart.h"
void LineChart::drawchart(std::vector<double>& lineChartVector, const int index) {
    size_t num_points = lineChartVector.size();
    int i;
    std::vector<double> xvals (num_points, 0.0);
    for (i=0; i<num_points; i++){
        xvals[i] = i + 1;
    }
    FILE * temp = fopen("tempadata.temp", "w");
    /*Opens an interface that one can use to send commands as if they were typing into the
     *     gnuplot command line.  "The -persistent" keeps the plot open even after your
     *     C program terminates.
     */
    FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
    size_t num_ponts = xvals.size();
    for (i=0; i < num_ponts; i++)
    {
        fprintf(temp, "%lf %lf \n", xvals[i], lineChartVector[i]); //Write the data to a temporary file
    }
    //fprintf(gnuplotPipe, "set term png \n");
    //fprintf(gnuplotPipe, "set output \"/Users/yutongpang/fdtdplot/fdtdplot-%d.png\" \n", index);
    fprintf(gnuplotPipe, "set title \"Electric Field vs Time Step\" \n"); //Send commands to gnuplot one by one.
    //fprintf(gnuplotPipe, "set yrange [-1:1] \n");
    fprintf(gnuplotPipe, "plot 'tempadata.temp'\n");
    fclose(temp);
    pclose(gnuplotPipe);
}
