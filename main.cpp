#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include "ncurses.h"

#include "Output.h"

int main() {
    Output output;
    WINDOW * mainwin;


    /*  Initialize ncurses  */

    if ( (mainwin = initscr()) == NULL ) {
        fprintf(stderr, "Error initialising ncurses.\n");
        exit(EXIT_FAILURE);
    }


    /*  Display "Hello, world!" in the centre of the
	screen, call refresh() to show our changes, and
	sleep() for a few seconds to get the full screen effect  */

    mvaddstr(4, 4, "X");
    mvaddstr(6, 6, "Y");
    mvaddstr(8, 8, "Z");
    refresh();
    sleep(3);


    /*  Clean up after ourselves  */

    delwin(mainwin);
    endwin();
    refresh();
    return 0;
}