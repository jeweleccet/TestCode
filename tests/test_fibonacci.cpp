#include <gtest/gtest.h>

#include "../src/fibonacci.h"

// Test cases for fibonacci
TEST(FibonacciTest, HandlesZeroInput) {
    EXPECT_EQ(fibonacci(0), 0);
}

TEST(FibonacciTest, HandlesOneInput) {
    EXPECT_EQ(fibonacci(1), 1);
}

TEST(FibonacciTest, HandlesPositiveInput) {
    EXPECT_EQ(fibonacci(5), 5);
    EXPECT_EQ(fibonacci(10), 55);
}

// main for Google Test
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
