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
    Cell cell;
    cell.live();
    EXPECT_EQ(true, cell.isAlive());
}

TEST(cell, knows_if_it_is_dead) {
    Cell cell;
    cell.die();
    EXPECT_EQ(true, cell.isDead());
}

TEST(cell, knows_its_coordinates) {
    Cell cell;
    cell.col = 123;
    cell.row = 456;
    EXPECT_EQ(123, cell.col);
    EXPECT_EQ(456, cell.row);

}

