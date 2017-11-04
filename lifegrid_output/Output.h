//
// Created by Anthony Clifton on 11/4/17.
//

#ifndef CONWAY_OUTPUT_H
#define CONWAY_OUTPUT_H


#include <vector>

class Output {

public:
    void setup();
    void draw(std::vector<std::vector<int>> grid);
    void teardown();

private:
    void drawOutline();
};


#endif //CONWAY_OUTPUT_H
