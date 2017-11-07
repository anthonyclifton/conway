Conway's Game of Life
====================

This is an implementation of Life in C++.  It uses ncurses to
display its output in the terminal.  The grid can be a
rectangle with any dimensions.  This implementation loads its
initial grid from a csv file specified on the command line in the
form:

`conway_run filename.csv`

Build and Run Instructions
===========================

Assuming you have CLion installed, you can build it from the command
line using: `/Applications/CLion.app/Contents/bin/cmake/bin/cmake --build /path/to/Conway/cmake-build-debug --target conway_run -- -j 4`

Two initial grids are provided in the root directory of the project:

`input.csv` which is a very simple grid.

`gosper-glider-gun.csv` Bill Gosper's Glider Gun which produces gliders forever.

Rules
========

_Any live cell with fewer than two live neighbours dies, as if caused by underpopulation._

_Any live cell with two or three live neighbours lives on to the next generation._

_Any live cell with more than three live neighbours dies, as if by overpopulation._

_Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction._