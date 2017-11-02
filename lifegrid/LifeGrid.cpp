//
// Created by Anthony Clifton on 10/31/17.
//

#include "LifeGrid.h"

LifeGrid::LifeGrid() {};

int LifeGrid::add (int x, int y) {
    return x + y;
}

std::vector<std::vector<int>> LifeGrid::update() {
    std::vector<std::vector<int>> output;
    int rowIndex = 0;
    for(std::vector<int> row: grid) {
        std::vector<int> output_row;
        int colIndex = 0;
        for(int cell: row) {
            int neighbors = countNeighbors(rowIndex, colIndex);
            if (cell == 1) {
                if (neighbors < 2) {
                    output_row.push_back(0);
                }
            } else {
                output_row.push_back(0);
            }
            ++colIndex;
        }
        output.push_back(output_row);
        ++rowIndex;
    }
    return output;
}

int LifeGrid::countNeighbors(int rowIndex, int colIndex) {
    int neighbors = 0;
    int start_row = (rowIndex == 0) ? 0 : rowIndex - 1;
    int end_row = (rowIndex == grid.size() - 1) ? rowIndex : rowIndex + 1;
    int start_col = (colIndex == 0) ? 0 : colIndex - 1;
    int end_col = (colIndex == grid[rowIndex].size() - 1) ? colIndex : colIndex + 1;

    for(int row = start_row; row <= end_row; ++row) {
        for (int col = start_col; col <= end_col; ++col) {
            if (row != rowIndex || col != colIndex) {
                if (grid[row][col] == 1) ++neighbors;
            }
        }
    }
    return neighbors;
}

