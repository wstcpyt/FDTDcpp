//
// Created by yutong pang on 6/24/15.
//

#ifndef FDTDCPP_FIELD_H
#define FDTDCPP_FIELD_H
#include <vector>
using namespace std;
class EMField
{
    const int gridsize;
    vector<double> EGrid;
    vector<double> MGrid;
public:
    EMField(int size);
    ~EMField(){};
    const int getGridsize() const {
        return gridsize;
    }
    vector<double> getEGrid() const {
        return EGrid;
    }
    vector<double> getMGrid() const {
        return MGrid;
    }
private:
};
#endif //FDTDCPP_FIELD_H
