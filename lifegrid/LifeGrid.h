//
// Created by Anthony Clifton on 10/31/17.
//

#ifndef CONWAY_LIFEGRID_H
#define CONWAY_LIFEGRID_H

#include <vector>

class LifeGrid {

public:
    std::vector<std::vector<int>> grid;

    LifeGrid();
    std::vector<std::vector<int>> update();
    int countNeighbors(int rowIndex, int colIndex);
};

#endif //LEARNINGCPLUSPLUS_LIFEGRID_H
