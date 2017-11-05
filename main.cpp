#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <csignal>
#include <chrono>
#include <thread>
#include <Cell.h>

#include "Loader.h"
#include "LifeGrid.h"
#include "Output.h"

Output output;

void sigint_handler(int s){
    output.teardown();
    printf("Caught signal %d\n",s);
    exit(1);

}

// Number of strings in array argv
// Array of command-line argument strings
// Array of environment variable strings
int main( int argc,
          char *argv[],
          char *envp[] ) {

    struct sigaction sigIntHandler;
    sigIntHandler.sa_handler = sigint_handler;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;
    sigaction(SIGINT, &sigIntHandler, nullptr);

    Loader loader;
    LifeGrid lifeGrid;
    int generations = 0;

    std::string filePath = argv[1];
    std::vector<std::vector<Cell>> startingGrid = loader.loadGrid(filePath);

    output.setup(startingGrid);

    output.draw(startingGrid, 0);
    sleep(1);

    std::vector<std::vector<Cell>> latestGrid = startingGrid;

    while(lifeGrid.countAlive(latestGrid) > 0) {
        generations++;
        latestGrid = lifeGrid.update(latestGrid);
        output.draw(latestGrid, generations);

        std::this_thread::sleep_for(std::chrono::milliseconds(100));

        if (lifeGrid.countAlive(latestGrid) == 0) break;
    }

    sleep(1);

    output.teardown();
    printf("Grid lasted for %i generations\n\n", generations);

    return 0;
}