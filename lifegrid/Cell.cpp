//
// Created by Anthony Clifton on 11/5/17.
//

#include "Cell.h"

Cell::Cell(int x, int y, bool aliveness): col(x), row(y), alive(aliveness) {}

void Cell::live() {
    alive = true;
}

void Cell::die() {
    alive = false;
}

bool Cell::isAlive() {
    return alive;
}

bool Cell::isDead() {
    return !alive;
}
