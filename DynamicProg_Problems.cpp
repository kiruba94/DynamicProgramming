#include "DynamicProg_Problems.hh"
#include <iostream>
#include <limits>
/**
 * @brief Find Fibonacci value for given integer
 * Time complexity = O(2^n)
 * 
 * @param n 
 * @return long int 
 */
long int fibonacci(int n)
{
    if (n <= 2)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

/**
 * @brief Find Fibonacci value of given integer but optimised using memoisation
 * Time complexity = O(n)
 * 
 * @param n 
 * @param fibMap 
 * @return long int 
 */
long int fibonacci_optimised(int n, std::unordered_map<int, long int> *fibMap)
{
    if (fibMap == nullptr)
        fibMap = new std::unordered_map<int, long int>();
    if (n <= 2)
        return 1;
    if (fibMap->find(n) != fibMap->end())
        return fibMap->at(n);
    (*fibMap)[n] = fibonacci_optimised(n - 1, fibMap) + fibonacci_optimised(n - 2, fibMap);
    return fibMap->at(n);
}

/**
 * @brief Given a grid with rows and columns find the paths to travel from top left to bottom right
 * Can move only to the right or bottom
 * Time complexity = O(2^(m+n))
 * 
 * @param rows 
 * @param columns 
 * @return long int 
 */
long int gridTraveller(int rows, int columns)
{
    if (rows == 0 || columns == 0)
        return 0;
    if (rows == 1 || columns == 1)
        return 1;
    return gridTraveller(rows - 1, columns) + gridTraveller(rows, columns - 1);
}

/**
 * @brief Given a grid with rows and columns find the paths to travel from top left to bottom right
 * Can move only to the right or bottom
 * Time complexity = O(m*n)
 * 
 * @param rows 
 * @param columns 
 * @param pathMap 
 * @return long int 
 */
long int gridTraveller_optimised(int rows, int columns, std::unordered_map<std::string, long int> *pathMap)
{
    if (pathMap == nullptr)
        pathMap = new std::unordered_map<std::string, long int>();
    if (rows == 0 || columns == 0)
        return 0;
    if (rows == 1 || columns == 1)
        return 1;
    std::string thisPair_1 = std::to_string(rows) + "," + std::to_string(columns);
    if (pathMap->find(thisPair_1) != pathMap->end())
        return pathMap->at(thisPair_1);

    (*pathMap)[thisPair_1] = gridTraveller_optimised(rows - 1, columns, pathMap) + gridTraveller_optimised(rows, columns - 1, pathMap);
    return pathMap->at(thisPair_1);
}
/**
 * @brief grid traveller algo for grid with obstacles
 * find all the paths that can reach end from start
 * 
 * @param matrix 
 * @param row 
 * @param column 
 * @param gridObsMap 
 * @return long int 
 */
long int gridTraveller_withObstacles(std::vector<std::vector<char>> &matrix, int row, int column, std::unordered_map<std::string, long int> *gridObsMap)
{
    if (gridObsMap == nullptr)
        gridObsMap = new std::unordered_map<std::string, long int>();
    std::string thisPos = std::to_string(row) + '_' + std::to_string(column);
    if (gridObsMap->count(thisPos) != 0)
        return gridObsMap->at(thisPos);
    if (column >= matrix[0].size())
        return 0;
    if (row >= matrix.size())
        return 0;
    if (matrix[row][column] == 'e')
        return 1;
    if (matrix[row][column] == 'x')
        return 0;
    (*gridObsMap)[thisPos] = gridTraveller_withObstacles(matrix, row + 1, column, gridObsMap) + gridTraveller_withObstacles(matrix, row, column + 1, gridObsMap);
    return gridObsMap->at(thisPos);
}

/**
 * @brief grid traveller algo for grid with obstacles
 * find the shortest path between start and end
 * 
 * @param matrix 
 * @param row 
 * @param column 
 * @param gridObsMap 
 * @return long int 
 */
long int gridTraveller_shortestPathlength(std::vector<std::vector<char>> &matrix, int row, int column, std::unordered_map<std::string, long int> *gridObsMap)
{
    //initialize memo
    if (gridObsMap == nullptr)
        gridObsMap = new std::unordered_map<std::string, long int>();
    //construct key for the current position
    std::string thisPos = std::to_string(row) + '_' + std::to_string(column);
    //check the memo if we have already calculated for this pos
    if (gridObsMap->count(thisPos) != 0)
        return gridObsMap->at(thisPos);
    //base case out of bounds
    if (column >= matrix[0].size())
        return std::numeric_limits<long int>::max();
    if (row >= matrix.size())
        return std::numeric_limits<long int>::max();

    //base case reached the end
    if (matrix[row][column] == 'e')
        return 1;
    //base case reached obstacle
    if (matrix[row][column] == 'x')
        return std::numeric_limits<long int>::max();
    
    //calculate the distance of path on either directions and choose the shortest path
    long int downPathLength = gridTraveller_shortestPathlength(matrix, row + 1, column, gridObsMap);
    long int rightPathLength = gridTraveller_shortestPathlength(matrix, row, column + 1, gridObsMap);
    long int shortestPathLength = downPathLength < rightPathLength ? downPathLength + 1 : rightPathLength + 1;

    //handlecase when both paths doesnt reach the end
    if (shortestPathLength < 0)
        return std::numeric_limits<long int>::max();

    //return
    return shortestPathLength;
}