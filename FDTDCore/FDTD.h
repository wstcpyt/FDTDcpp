//
// Created by yutong pang on 6/24/15.
//

#ifndef FDTDCPP_FDTD_H
#define FDTDCPP_FDTD_H

#define SIZE 200
#define MAXTIME 250

class FDTD{
    int time;
public:
    FDTD(){};
    ~FDTD(){};
    void runSimulation();
};
#endif //FDTDCPP_FDTD_H
