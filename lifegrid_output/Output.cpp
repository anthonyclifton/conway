//
// Created by Anthony Clifton on 11/4/17.
//

#include <cstdlib>
#include <cstdio>
#include <string>
#include "ncurses.h"

#include "Output.h"

WINDOW * mainwin;

void Output::setup(std::vector<std::vector<int>> &grid) {

    // Initialize ncurses
    if ( (mainwin = initscr()) == nullptr ) {
        fprintf(stderr, "Error initialising ncurses.\n");
        exit(EXIT_FAILURE);
    }

    drawOutline(grid);
}

void Output::draw(std::vector<std::vector<int>> grid, int generation) {
    long height = grid.size();
    long width = grid[0].size();
    int rowIndex = 0;
    for(std::vector<int> row: grid) {
        std::vector<int> output_row;
        int colIndex = 0;
        for (int cell: row) {
            mvaddch(STARTING_Y + rowIndex + 1, STARTING_X + colIndex + 1, (cell) ? 'X' : ' ');
            colIndex++;
        }
        rowIndex++;
    }

    mvaddstr(STARTING_Y - 2, STARTING_X - 2, "Gen: ");
    mvaddstr(STARTING_Y - 2, STARTING_X + 3, std::to_string(generation).c_str());
    move(STARTING_Y + int(height) + 2, STARTING_X + int(width) + 2);

    refresh();
}

void Output::teardown() {
    delwin(mainwin);
    endwin();
    refresh();
}

void Output::drawOutline(std::vector<std::vector<int>> grid) {
    // todo protect against emptiness, it causes seg fault
    long height = grid.size();
    long width = grid[0].size();

    for(int col = STARTING_X; col <= STARTING_X + width + 1; col++) {
        // top
        mvaddstr(STARTING_Y, col, "-");
        // bottom
        mvaddstr(STARTING_Y + height + 1, col, "-");
    }

    for(int row = STARTING_Y; row <= STARTING_Y + height + 1; row++) {
        // left
        mvaddstr(row, STARTING_X, "|");
        // right
        mvaddstr(row, STARTING_X + width + 1, "|");
    }

    refresh();
}
