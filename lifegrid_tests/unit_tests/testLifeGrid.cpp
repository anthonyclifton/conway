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
        // Code here will be called immediately after each test
        // (right before the destructor).
    }
};

TEST(lifegrid, update_method_kills_lonely_cells) {
    std::vector<std::vector<int>> starting_grid = {
            {1},
            {0}
    };
    std::vector<std::vector<int>> expected_grid = {
            {0},
            {0}
    };
    LifeGrid lifeGrid;
    std::vector<std::vector<int>> updated_grid = lifeGrid.update(starting_grid);
    EXPECT_EQ(expected_grid, updated_grid);
}

TEST(lifegrid, update_method_leaves_happy_cells_with_2_neighbors_alive) {
    std::vector<std::vector<int>> starting_grid = {
            {1, 0},
            {1, 1}
    };
    std::vector<std::vector<int>> expected_grid = {
            {1, 1},
            {1, 1}
    };
    LifeGrid lifeGrid;
    std::vector<std::vector<int>> updated_grid = lifeGrid.update(starting_grid);
    EXPECT_EQ(expected_grid, updated_grid);
}

TEST(lifegrid, update_method_leaves_happy_cells_with_3_neighbors_alive) {
    std::vector<std::vector<int>> starting_grid = {
            {1, 1},
            {1, 1}
    };
    std::vector<std::vector<int>> expected_grid = {
            {1, 1},
            {1, 1}
    };
    LifeGrid lifeGrid;
    std::vector<std::vector<int>> updated_grid = lifeGrid.update(starting_grid);
    EXPECT_EQ(expected_grid, updated_grid);
}

TEST(lifegrid, update_method_kills_cells_with_4_neighbors) {
    std::vector<std::vector<int>> starting_grid = {
            {0, 1, 0},
            {1, 1, 1},
            {0, 1, 0}
    };
    std::vector<std::vector<int>> expected_grid = {
            {1, 1, 1},
            {1, 0, 1},
            {1, 1, 1}
    };
    LifeGrid lifeGrid;
    std::vector<std::vector<int>> updated_grid = lifeGrid.update(starting_grid);
    EXPECT_EQ(expected_grid, updated_grid);
}

TEST(lifegrid, update_method_experiment_1) {
    std::vector<std::vector<int>> starting_grid = {
            {0, 0},
            {1, 0}
    };
    std::vector<std::vector<int>> expected_grid = {
            {0, 0},
            {0, 0}
    };
    LifeGrid lifeGrid;
    std::vector<std::vector<int>> updated_grid = lifeGrid.update(starting_grid);
    EXPECT_EQ(expected_grid, updated_grid);
}

TEST(lifegrid, update_method_does_first_glider_step) {
    std::vector<std::vector<int>> starting_grid = {
            {0, 0, 0, 0},
            {1, 0, 0, 0},
            {0, 1, 1, 0},
            {1, 1, 0, 0}
    };
    std::vector<std::vector<int>> expected_grid = {
            {0, 0, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 1, 0},
            {1, 1, 1, 0}
    };
    LifeGrid lifeGrid;
    std::vector<std::vector<int>> updated_grid = lifeGrid.update(starting_grid);
    EXPECT_EQ(expected_grid, updated_grid);
}

//TEST(lifegrid, update_method_kills_overpopulated_cells) {
//    std::vector<std::vector<int>> starting_grid = {
//            {1, 1, 1},
//            {1, 0, 1}
//    };
//    std::vector<std::vector<int>> expected_grid = {
//            {1, 0, 1},
//            {1, 0, 1}
//    };
//    LifeGrid lifeGrid;
//    lifeGrid.grid = starting_grid;
//    std::vector<std::vector<int>> updated_grid = lifeGrid.update();
//    EXPECT_EQ(expected_grid, updated_grid);
//}
//
//TEST(lifegrid, update_method_generates_new_cells) {
//    std::vector<std::vector<int>> starting_grid = {
//            {1, 1},
//            {1, 0}
//    };
//    std::vector<std::vector<int>> expected_grid = {
//            {1, 1},
//            {1, 1}
//    };
//    LifeGrid lifeGrid;
//    lifeGrid.grid = starting_grid;
//    std::vector<std::vector<int>> updated_grid = lifeGrid.update();
//    EXPECT_EQ(expected_grid, updated_grid);
//}
//
//TEST(lifegrid, count_neighbors_returns_0_when_no_neighbors) {
//    std::vector<std::vector<int>> current_grid = {{1}};
//    LifeGrid lifeGrid;
//    lifeGrid.grid = current_grid;
//    int neighbors = lifeGrid.countNeighbors(0,0);
//    EXPECT_EQ(0, neighbors);
//}
//
//TEST(lifegrid, count_neighbors_returns_1_when_one_neighbor) {
//    std::vector<std::vector<int>> current_grid = {{1, 1}};
//    LifeGrid lifeGrid;
//    lifeGrid.grid = current_grid;
//    int neighbors = lifeGrid.countNeighbors(0,0);
//    EXPECT_EQ(1, neighbors);
//}
//
//TEST(lifegrid, count_neighbors_returns_2_when_one_neighbor) {
//    std::vector<std::vector<int>> current_grid = {{1, 1}, {1, 0}};
//    LifeGrid lifeGrid;
//    lifeGrid.grid = current_grid;
//    int neighbors = lifeGrid.countNeighbors(0,0);
//    EXPECT_EQ(2, neighbors);
//}