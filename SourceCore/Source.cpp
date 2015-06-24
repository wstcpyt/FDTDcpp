//
// Created by yutong pang on 6/23/15.
//
#include <iostream>
#include <math.h>
using namespace std;

#include "Source.h"
Source::Source() {
    cout << "Source Object is being created" << endl;
}

Source::~Source() {
    cout << "Source Object is being deleted" << endl;
}

double Source::addSource(const int time, const string type) const {
    if (type == "hardsource"){
        return exp(-(time - 30.) * (time - 30.) / 100.);
    }
    else {
        return 0.0;
    }
}