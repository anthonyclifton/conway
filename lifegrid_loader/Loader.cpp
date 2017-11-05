//
// Created by Anthony Clifton on 11/1/17.
//

#include <sstream>
#include <Cell.h>
#include "Loader.h"


Loader::Loader() {};

std::vector<std::vector<Cell>> Loader::loadGrid(const std::string& filePath) {
    std::ifstream  data(filePath);
    std::string line;
    std::vector<std::vector<Cell>> parsedCSV;
    int y = 0;
    while(std::getline(data,line))
    {
        std::stringstream lineStream(line);
        std::string cell;
        std::vector<Cell> parsedRow;
        int x = 0;
        while(std::getline(lineStream,cell,','))
        {
            Cell * newCell = new Cell(x, y, (cell.at(0) == '1'));
            parsedRow.push_back(*newCell);
            x++;
        }

        parsedCSV.push_back(parsedRow);
        y++;
    }
    return parsedCSV;
}
