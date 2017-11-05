//
// Created by Anthony Clifton on 11/5/17.
//

#ifndef CONWAY_CELL_H
#define CONWAY_CELL_H


class Cell {
public:
    int col;
    int row;
    bool alive = false;

    Cell(int x, int y, bool alive);

    void live();
    void die();
    bool isAlive();
    bool isDead();
};


#endif //CONWAY_CELL_H
