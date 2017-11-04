//
// Created by Anthony Clifton on 11/4/17.
//

#include <cstdlib>
#include <cstdio>
#include "ncurses.h"

#include "Output.h"

WINDOW * mainwin;

void Output::setup() {


    /*  Initialize ncurses  */

    if ( (mainwin = initscr()) == nullptr ) {
        fprintf(stderr, "Error initialising ncurses.\n");
        exit(EXIT_FAILURE);
    }
}

void Output::draw(std::vector<std::vector<int>>) {
}

void Output::teardown() {
    delwin(mainwin);
    endwin();
    refresh();
}

void drawOutline() {

}
