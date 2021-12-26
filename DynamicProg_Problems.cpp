#include "DynamicProg_Problems.hh"

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