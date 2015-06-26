//
// Created by yutong pang on 6/26/15.
//
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "LineChart.h"
void LineChart::drawchart(std::vector<double>& lineChartVector) {
    unsigned long num_points = lineChartVector.size();
    int i;
    std::vector<double> xvals (num_points, 0.0);
    for (i=0; i<num_points; i++){
        xvals[i] = i + 1;
    }
    FILE * temp = fopen("data.temp", "w");
    /*Opens an interface that one can use to send commands as if they were typing into the
     *     gnuplot command line.  "The -persistent" keeps the plot open even after your
     *     C program terminates.
     */
    FILE * gnuplotPipe = popen ("gnuplot -persistent", "w");
    unsigned long num_ponts = xvals.size();
    for (i=0; i < num_ponts; i++)
    {
        fprintf(temp, "%lf %lf \n", xvals[i], lineChartVector[i]); //Write the data to a temporary file
    }
    fprintf(gnuplotPipe, "set title \"Electric Field vs Time Step at 1 Grid Point\" \n"); //Send commands to gnuplot one by one.
    fprintf(gnuplotPipe, "plot 'data.temp' \n");
    pclose(gnuplotPipe);
    fclose(temp);
}
