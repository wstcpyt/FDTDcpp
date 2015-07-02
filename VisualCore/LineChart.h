//
// Created by yutong pang on 6/26/15.
//

#ifndef FDTDCPP_LINECHART_H
#define FDTDCPP_LINECHART_H
class LineChart{
public:
    LineChart(){};
    ~LineChart(){};
    void drawchart(std::vector<double>& lineChartVector, const int index);
};
#endif //FDTDCPP_LINECHART_H
