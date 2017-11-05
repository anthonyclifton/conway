//
// Created by Anthony Clifton on 10/31/17.
//

#include "LifeGrid.h"
#include "Cell.h"

LifeGrid::LifeGrid() {};

std::vector<std::vector<Cell>> LifeGrid::update(std::vector<std::vector<Cell>> grid) {
    std::vector<std::vector<Cell>> output;

    for(std::vector<Cell> row: grid) {
        std::vector<Cell> output_row;
        for(Cell cell: row) {
            int neighbors = countNeighbors(cell, grid);
            bool aliveness;
            if (cell.isAlive()) {
                // lonely cells die (alive, less than 2 neighbors)
                // happy cells live (alive, 2 or 3 neighbors)
                // crowded cells die (alive, more than 3 neighbors)
                // new cells appear (dead, 3 neighbors or more)
                aliveness = (neighbors == 2 || neighbors == 3);
            } else {
                aliveness = (neighbors == 3);
            }
            Cell * updatedCell = new Cell(cell.col, cell.row, aliveness);
            output_row.push_back(*updatedCell);
        }
        output.push_back(output_row);
    }
    return output;
}

int LifeGrid::countNeighbors(Cell cell, std::vector<std::vector<Cell>> grid) {
    int neighbors = 0;
    int start_row = (cell.row == 0) ? 0 : cell.row - 1;
    int end_row = (cell.row == grid.size() - 1) ? cell.row : cell.row + 1;
    int start_col = (cell.col == 0) ? 0 : cell.col - 1;
    int end_col = (cell.col == grid[cell.row].size() - 1) ? cell.col : cell.col + 1;

    for(int row = start_row; row <= end_row; row++) {
        for (int col = start_col; col <= end_col; col++) {
            if (isNotMe(cell, col, row)) {
                if (grid[row][col].isAlive()) neighbors++;
            }
        }
    }
    return neighbors;
}

bool LifeGrid::isNotMe(Cell cell, int theirX, int theirY) {
    return !((cell.col == theirX) && (cell.row == theirY));
}

int LifeGrid::countAlive(std::vector<std::vector<Cell>> grid) {
    int countAlive = 0;
    for(std::vector<Cell> row: grid) {
        for(Cell cell: row) {
            if (cell.isAlive()) countAlive++;
        }
    }
    return countAlive;
};
