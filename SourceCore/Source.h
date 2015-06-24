//
// Created by yutong pang on 6/23/15.
//

#ifndef FDTDCPP_SOURCE_H
#define FDTDCPP_SOURCE_H
#include <string>
using namespace std;
class Source
{
public:
    Source();
    ~Source();
    double addSource(const int time, const string type) const ;

private:

};

#endif //FDTDCPP_SOURCE_H
