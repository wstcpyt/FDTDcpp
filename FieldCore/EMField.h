//
// Created by yutong pang on 6/24/15.
//

#ifndef FDTDCPP_FIELD_H
#define FDTDCPP_FIELD_H
#include <vector>
class EMField
{
    const int gridsize;
    int gridpoint;
    const double imp0 = 377.0;
public:
    EMField(int size);
    ~EMField(){};
    void updateEGrid(std::vector<double>& EGrid_z, std::vector<double>& HGrid_y);
    void updateHGrid(std::vector<double>& EGrid_z, std::vector<double>& HGrid_y);
    const int getGridsize() const {
        return gridsize;
    }
private:
};
#endif //FDTDCPP_FIELD_H
