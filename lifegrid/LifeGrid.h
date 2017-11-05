//
// Created by Anthony Clifton on 10/31/17.
//

#ifndef CONWAY_LIFEGRID_H
#define CONWAY_LIFEGRID_H

#include <vector>
#include "Cell.h"

class LifeGrid {

public:
    LifeGrid();
    std::vector<std::vector<Cell>> update(std::vector<std::vector<Cell>> grid);
    int countNeighbors(Cell cell, std::vector<std::vector<Cell>> grid);
    int countAlive(std::vector<std::vector<Cell>> grid);

private:
    bool isNotMe(Cell cell, int theirX, int theirY);
};

#endif //LEARNINGCPLUSPLUS_LIFEGRID_H
