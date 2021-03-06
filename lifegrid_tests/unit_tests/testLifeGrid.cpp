//
// Created by Anthony Clifton on 10/31/17.
//
#include "gtest/gtest.h"
#include "LifeGrid.h"

class LifeGridTest : public ::testing::Test {

protected:

    virtual void SetUp() {
    }

    virtual void TearDown() {
    }
};

TEST(lifegrid, update_method_kills_lonely_cells) {
    std::vector<std::vector<Cell>> starting_grid = {
            {Cell::Cell(0,0,true)},
            {Cell::Cell(1,0,false)}
    };

    LifeGrid lifeGrid;
    std::vector<std::vector<Cell>> updated_grid = lifeGrid.update(starting_grid);
    EXPECT_EQ(true, updated_grid[0][0].isDead());
}

TEST(lifegrid, update_method_leaves_happy_cells_with_2_neighbors_alive) {
    std::vector<std::vector<Cell>> starting_grid = {
            {Cell::Cell(0,0,true), Cell::Cell(1,0,false)},
            {Cell::Cell(0,1,true), Cell::Cell(1,1,true)}
    };
    LifeGrid lifeGrid;
    std::vector<std::vector<Cell>> updated_grid = lifeGrid.update(starting_grid);
    EXPECT_EQ(true, updated_grid[0][1].isAlive());
}

TEST(lifegrid, update_method_leaves_happy_cells_with_3_neighbors_alive) {
    std::vector<std::vector<Cell>> starting_grid = {
            {Cell::Cell(0,0,true), Cell::Cell(1,0,true)},
            {Cell::Cell(0,1,true), Cell::Cell(1,1,true)}
    };
    LifeGrid lifeGrid;
    std::vector<std::vector<Cell>> updated_grid = lifeGrid.update(starting_grid);
    EXPECT_EQ(true, updated_grid[0][0].isAlive());
    EXPECT_EQ(true, updated_grid[1][0].isAlive());
    EXPECT_EQ(true, updated_grid[0][1].isAlive());
    EXPECT_EQ(true, updated_grid[1][1].isAlive());
}

TEST(lifegrid, update_method_kills_cells_with_4_neighbors) {
    std::vector<std::vector<Cell>> starting_grid = {
            {Cell::Cell(0,0,false), Cell::Cell(1,0,true), Cell::Cell(2,0,false)},
            {Cell::Cell(0,1,true), Cell::Cell(1,1,true), Cell::Cell(2,1,true)},
            {Cell::Cell(0,2,false), Cell::Cell(1,2,true), Cell::Cell(2,2,false)},
    };
    LifeGrid lifeGrid;
    std::vector<std::vector<Cell>> updated_grid = lifeGrid.update(starting_grid);
    EXPECT_EQ(false, updated_grid[1][1].isAlive());
}

TEST(lifegrid, update_method_generates_new_cells) {
    std::vector<std::vector<Cell>> starting_grid = {
            {Cell::Cell(0,0,true), Cell::Cell(1,0,true)},
            {Cell::Cell(0,1,true), Cell::Cell(1,1,false)}
    };
    LifeGrid lifeGrid;
    std::vector<std::vector<Cell>> updated_grid = lifeGrid.update(starting_grid);
    EXPECT_EQ(true, updated_grid[1][1].isAlive());
}

TEST(lifegrid, count_neighbors_returns_0_when_no_neighbors) {
    std::vector<std::vector<Cell>> current_grid = {{Cell::Cell(0,0,true)}};
    LifeGrid lifeGrid;
    int neighbors = lifeGrid.countNeighbors(current_grid[0][0], current_grid);
    EXPECT_EQ(0, neighbors);
}

TEST(lifegrid, count_neighbors_returns_1_when_one_neighbor) {
    std::vector<std::vector<Cell>> current_grid = {{Cell::Cell(0,0,true), Cell::Cell(1,0,true)}};
    LifeGrid lifeGrid;
    int neighbors = lifeGrid.countNeighbors(current_grid[0][0], current_grid);
    EXPECT_EQ(1, neighbors);
}

TEST(lifegrid, count_neighbors_returns_2_when_one_neighbor) {
    std::vector<std::vector<Cell>> current_grid = {
            {Cell::Cell(0,0,true), Cell::Cell(1,0,true)},
            {Cell::Cell(0,1,true), Cell::Cell(1,1,false)}};
    LifeGrid lifeGrid;
    int neighbors = lifeGrid.countNeighbors(current_grid[0][0], current_grid);
    EXPECT_EQ(2, neighbors);
}