#include "gtest/gtest.h"
#include "../DynamicProg_Problems.hh"

TEST(fibonacci_Test, test1)
{
    EXPECT_EQ(fibonacci(1), 1);
    EXPECT_EQ(fibonacci(2), 1);
    EXPECT_EQ(fibonacci(3), 2);
    EXPECT_EQ(fibonacci(4), 3);
    EXPECT_EQ(fibonacci(5), 5);
    EXPECT_EQ(fibonacci(6), 8);
    EXPECT_EQ(fibonacci(7), 13);
    EXPECT_EQ(fibonacci(50), 12586269025);
}
TEST(fibonacci_optimised_Test, test1)
{
    EXPECT_EQ(fibonacci_optimised(1), 1);
    EXPECT_EQ(fibonacci_optimised(2), 1);
    EXPECT_EQ(fibonacci_optimised(3), 2);
    EXPECT_EQ(fibonacci_optimised(4), 3);
    EXPECT_EQ(fibonacci_optimised(5), 5);
    EXPECT_EQ(fibonacci_optimised(6), 8);
    EXPECT_EQ(fibonacci_optimised(7), 13);
    EXPECT_EQ(fibonacci_optimised(50), 12586269025);
}
TEST(grid_traveler_Test, normal_recursion)
{
    EXPECT_EQ(gridTraveller(2, 3), 3);
    EXPECT_EQ(gridTraveller(10, 10), 48620);
    EXPECT_EQ(gridTraveller(18, 18), 2333606220);
}
TEST(grid_traveler_Test, recursion_with_memo)
{
    EXPECT_EQ(gridTraveller_optimised(2, 3), 3);
    EXPECT_EQ(gridTraveller_optimised(10, 10), 48620);
    EXPECT_EQ(gridTraveller_optimised(18, 18), 2333606220);
}