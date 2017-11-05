//
// Created by Anthony Clifton on 11/1/17.
//

#ifndef LIFEGRID_LOADER_H
#define LIFEGRID_LOADER_H

#include <Cell.h>
#include "vector"
#include "fstream"

class Loader {

public:
    Loader();
    std::vector<std::vector<Cell>> loadGrid(const std::string& filePath);
};


#endif //LIFEGRID_LOADER_H
