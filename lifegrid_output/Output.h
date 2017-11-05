//
// Created by Anthony Clifton on 11/4/17.
//

#ifndef CONWAY_OUTPUT_H
#define CONWAY_OUTPUT_H


#include <vector>

class Output {

    const int STARTING_X = 4;
    const int STARTING_Y = 4;

public:
    void setup(std::vector<std::vector<Cell>> &grid);
    void draw(std::vector<std::vector<Cell>> grid, int generation);
    void teardown();

private:
    void drawOutline(std::vector<std::vector<Cell>> grid);
};


#endif //CONWAY_OUTPUT_H
