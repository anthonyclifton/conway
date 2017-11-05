//
// Created by Anthony Clifton on 10/31/17.
//

#ifndef CONWAY_LIFEGRID_H
#define CONWAY_LIFEGRID_H

#include <vector>

class LifeGrid {

public:
    LifeGrid();
    std::vector<std::vector<int>> update(std::vector<std::vector<int>> grid);
    int countNeighbors(int rowIndex, int colIndex, std::vector<std::vector<int>> grid);
    int countAlive(std::vector<std::vector<int>> grid);

private:
    bool isNotMe(int myX, int myY, int theirX, int theirY);
};

#endif //LEARNINGCPLUSPLUS_LIFEGRID_H
