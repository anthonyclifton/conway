#include "gtest/gtest.h"
#include "Cell.h"

class CellTest : public ::testing::Test {

protected:

    virtual void SetUp() {
    }

    virtual void TearDown() {
    }
};

TEST(cell, knows_if_it_is_alive) {
    Cell * cell = new Cell(0,0,false);
    cell->live();
    EXPECT_EQ(true, cell->isAlive());
}

TEST(cell, knows_if_it_is_dead) {
    Cell * cell = new Cell(0,0,true);
    cell->die();
    EXPECT_EQ(true, cell->isDead());
}


