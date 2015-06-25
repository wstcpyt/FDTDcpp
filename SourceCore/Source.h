//
// Created by yutong pang on 6/23/15.
//

#ifndef FDTDCPP_SOURCE_H
#define FDTDCPP_SOURCE_H
class Source
{
public:
    Source();
    ~Source();
    double addSource(const int time) const{
        return 1.0;
    };

private:

};

#endif //FDTDCPP_SOURCE_H
