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

TEST(lifegrid, constructor_exists) {
    LifeGrid lifeGrid;
    EXPECT_EQ(4, lifeGrid.add(2, 2));
}

TEST(lifegrid, constructor_something) {
    LifeGrid lifeGrid;
    EXPECT_NE(6, lifeGrid.add(2, 2));
}