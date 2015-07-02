//
// Created by yutong pang on 7/1/15.
//

#include "TFSFTMz.h"
#include "constant.h"
TFSFTMz::TFSFTMz() {
    printf("Grid is %d by %d cell.\n", STRUCTURE_SIZE_X, STRUCTURE_SIZE_Y);
    printf("Enter indices for first point in TF region: ");
    scanf(" %d %d", &firstX, &firstY);
    printf("Enter indices for last point in TF region: ");
    scanf(" %d %d", &lastX, &lastY);
}
TFSFTMz::TFSFTMz(const int fX, const int fY, const int lX, const int lY): firstX(fX), firstY(fY), lastX(lX), lastY(lY) {
}

void TFSFTMz::addBounday(std::vector<std::vector<double>> &Ez, std::vector<std::vector<double>> &Hx,
                         std::vector<std::vector<double>> &Hy, const int& time)
{
    correcHyalongleftedge(Hy, time);
}

void TFSFTMz::correcHyalongleftedge(std::vector<std::vector<double>> &Hy, const int& time) {
    int gridx = firstX - 1;
    int gridy;
    for (gridy = firstX; gridy <= lastY; gridy++){
        Hy[gridx][gridy] -= 1;
    }
}