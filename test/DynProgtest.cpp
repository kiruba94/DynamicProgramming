#include "gtest/gtest.h"
#include "../DynamicProg_Problems.hh"
#include <limits>
/*
*       FIBONACCI SERIES
*/
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

/*
*           GRID TRAVELLER ALGORITHMS TEST CASES
* 
*           Only Right and Down movement allowed
*/
//Find the total number of paths between start and end in a grid  without obstacles
TEST(grid_traveler_noObs_Test, normal_recursion)
{
    EXPECT_EQ(gridTraveller(2, 3), 3);
    EXPECT_EQ(gridTraveller(10, 10), 48620);
    EXPECT_EQ(gridTraveller(18, 18), 2333606220);
}
TEST(grid_traveler_noObs_Test, recursion_with_memo)
{
    EXPECT_EQ(gridTraveller_optimised(2, 3), 3);
    EXPECT_EQ(gridTraveller_optimised(10, 10), 48620);
    EXPECT_EQ(gridTraveller_optimised(18, 18), 2333606220);
}
//Find the total number of paths between start and end in a grid with obstacled
TEST(grid_traveller_obs_FindAllPaths, Test_huge_matrix_with_no_obstacles)
{
    std::vector<std::vector<char>> matrix = {{'s', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'e'}};

    EXPECT_EQ(gridTraveller_withObstacles(matrix, 0, 0), 573166440);
}
TEST(grid_traveller_obs_FindAllPaths, Test_huge_matrix_with_one_path)
{
    std::vector<std::vector<char>> matrix = {{'s', '0', 'x', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'x', '0', 'x', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', 'x', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', 'x', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', 'x', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', 'x', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', 'x', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', 'x', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', 'x', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', 'x', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', 'x', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', 'x', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', 'x', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', 'x', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', 'x', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', 'x', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', 'x', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', 'x', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', 'x', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', 'x', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'e'}};
    EXPECT_EQ(gridTraveller_withObstacles(matrix, 0, 0), 1);
}
TEST(grid_traveller_obs_FindAllPaths, Test_small_matrix_with_known_paths)
{
    std::vector<std::vector<char>> matrix = {{'s', '0', '0', 'x', '0'},
                                             {'0', 'x', '0', '0', 'x'},
                                             {'0', '0', 'x', '0', '0'},
                                             {'x', '0', '0', 'x', '0'},
                                             {'x', '0', '0', '0', 'e'}};
    EXPECT_EQ(gridTraveller_withObstacles(matrix, 0, 0), 3);
}
TEST(grid_traveller_obs_FindAllPaths, Test_small_matrix_with_no_paths)
{
    std::vector<std::vector<char>> matrix = {{'s', '0', '0', 'x', '0'},
                                             {'0', 'x', '0', '0', 'x'},
                                             {'0', '0', 'x', '0', '0'},
                                             {'x', '0', '0', 'x', 'x'},
                                             {'x', '0', '0', 'x', 'e'}};
    EXPECT_EQ(gridTraveller_withObstacles(matrix, 0, 0), 0);
}
//Find the shortedt path from start to end in a grid
TEST(shortest_path_matrix, Test1)
{
    std::vector<std::vector<char>> matrix = {{'s', '0', 'e', 'x', '0'},
                                             {'0', 'x', '0', '0', 'x'},
                                             {'0', 'x', 'x', '0', '0'},
                                             {'0', 'x', '0', 'x', '0'},
                                             {'0', '0', '0', '0', '0'}};
    EXPECT_EQ(gridTraveller_shortestPathlength(matrix, 0, 0), 3);
}
TEST(shortest_path_matrix, Test2)
{
    std::vector<std::vector<char>> matrix = {{'s', '0', '0', 'x', '0'},
                                             {'0', 'x', '0', '0', 'e'},
                                             {'0', 'x', 'x', '0', '0'},
                                             {'0', 'x', '0', 'x', '0'},
                                             {'0', '0', '0', '0', '0'}};
    EXPECT_EQ(gridTraveller_shortestPathlength(matrix, 0, 0), 6);
}
TEST(shortest_path_matrix, Test3)
{
    std::vector<std::vector<char>> matrix = {{'s', '0', '0', 'x', '0'},
                                             {'0', 'x', '0', '0', 'x'},
                                             {'0', 'x', 'x', '0', '0'},
                                             {'0', 'x', '0', 'x', '0'},
                                             {'0', '0', '0', '0', 'e'}};
    EXPECT_EQ(gridTraveller_shortestPathlength(matrix, 0, 0), 9);
}
TEST(shortest_path_matrix, Test_noPathFound)
{
    std::vector<std::vector<char>> matrix = {{'s', '0', '0', 'x', '0'},
                                             {'0', 'x', '0', '0', 'x'},
                                             {'0', 'x', 'x', '0', '0'},
                                             {'0', 'x', '0', 'x', '0'},
                                             {'0', '0', '0', '0', '0'}};
    EXPECT_EQ(gridTraveller_shortestPathlength(matrix, 0, 0), std::numeric_limits<long int>::max());
}
TEST(shortest_path_matrix, Test_huge_matrix){
    std::vector<std::vector<char>> matrix = {{'s', '0', 'x', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'x', '0', 'x', '0', '0', '0', 'x', '0', '0', 'x', 'x', '0', 'x', '0'},
                                             {'0', '0', '0', '0', '0', 'x', '0', '0', '0', '0', 'x', '0', '0', '0'},
                                             {'x', '0', 'x', '0', '0', '0', '0', '0', 'x', '0', '0', '0', '0', '0'},
                                             {'0', '0', 'x', 'x', 'x', '0', 'x', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', 'x', 'x', '0', 'x', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', 'x', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', 'x', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', 'x', '0', '0', '0', 'x', '0', 'x', '0', '0', '0', '0', '0'},
                                             {'0', '0', '0', '0', '0', '0', '0', 'x', '0', '0', '0', '0', '0', '0'},
                                             {'0', '0', 'x', '0', '0', '0', '0', 'x', '0', 'x', '0', '0', '0', '0'},
                                             {'0', '0', 'x', '0', '0', '0', '0', '0', 'x', '0', '0', 'x', '0', '0'},
                                             {'0', '0', 'x', '0', '0', '0', '0', '0', '0', 'x', '0', '0', 'x', '0'},
                                             {'0', '0', '0', '0', '0', '0', '0', '0', '0', 'x', '0', '0', '0', '0'},
                                             {'0', '0', 'x', '0', '0', '0', 'x', '0', '0', 'x', '0', 'x', '0', '0'},
                                             {'0', '0', 'x', '0', '0', '0', '0', '0', '0', 'x', '0', '0', '0', '0'},
                                             {'0', '0', 'x', '0', '0', '0', '0', '0', '0', 'x', '0', '0', 'x', '0'},
                                             {'0', '0', 'x', '0', 'x', 'x', '0', '0', '0', 'x', '0', 'x', '0', '0'},
                                             {'0', '0', 'x', '0', '0', '0', 'x', '0', '0', 'x', '0', '0', '0', '0'},
                                             {'0', '0', 'x', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'x'},
                                             {'0', '0', '0', '0', '0', 'x', '0', '0', '0', '0', '0', '0', '0', 'e'}};
    EXPECT_EQ(gridTraveller_shortestPathlength(matrix, 0, 0), 34);
}