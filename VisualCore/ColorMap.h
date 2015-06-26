//
// Created by yutong pang on 6/26/15.
//

#ifndef FDTDCPP_COLORMAP_H
#define FDTDCPP_COLORMAP_H

#include <vector>
class ColorMap{
public:
    ColorMap(){};
    ~ColorMap(){};
    void drawchart(std::vector<std::vector<double>>& ColorMapVector);
};
#endif //FDTDCPP_COLORMAP_H
