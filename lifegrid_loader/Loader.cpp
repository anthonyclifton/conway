//
// Created by Anthony Clifton on 11/1/17.
//

#include <sstream>
#include "Loader.h"


Loader::Loader() {};

std::vector<std::vector<int>> Loader::loadGrid(const std::string& filePath) {
    std::ifstream  data(filePath);
    std::string line;
    std::vector<std::vector<int>> parsedCSV;
    while(std::getline(data,line))
    {
        std::stringstream lineStream(line);
        std::string cell;
        std::vector<int> parsedRow;
        while(std::getline(lineStream,cell,','))
        {
            parsedRow.push_back(cell.at(0) == '1' ? 1 : 0);
        }

        parsedCSV.push_back(parsedRow);
    }
    return parsedCSV;
}
