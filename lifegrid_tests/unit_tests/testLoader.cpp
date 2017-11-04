//
// Created by Anthony Clifton on 10/31/17.
//
#include "gtest/gtest.h"
#include "Loader.h"

class LoaderTest : public ::testing::Test {

protected:

    virtual void SetUp() {
    }

    virtual void TearDown() {
    }
};

TEST(loader, silly_test) {
    EXPECT_EQ(1, 1);
}
