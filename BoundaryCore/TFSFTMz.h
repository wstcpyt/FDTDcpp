//
// Created by yutong pang on 7/1/15.
//

#ifndef FDTDCPP_TFSFTMZ_H
#define FDTDCPP_TFSFTMZ_H

#include <vector>

class TFSFTMz {
    int firstX, firstY, lastX, lastY;
public:
    TFSFTMz();

    TFSFTMz(const int firstX, const int firstY, const int lastX, const int lastY);

    ~TFSFTMz() { };

    int getFirstX() const {
        return firstX;
    }

    int getFirstY() const {
        return firstY;
    }

    int getLastX() const {
        return lastX;
    }

    int getLastY() const {
        return lastY;
    }

    void addBounday(std::vector<std::vector<double>>& Ez, std::vector<std::vector<double>>& Hx,
                    std::vector<std::vector<double>>& Hy, const int& time);

private:
    void correcHyalongleftedge(std::vector<std::vector<double>>& Hy, const int& time);
};

#endif //FDTDCPP_TFSFTMZ_H
