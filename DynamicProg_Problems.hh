#ifndef DYNAMIC_PROG_HH
#define DYNAMIC_PROG_HH
#include<unordered_map>
#include<string>
#include<vector>


long int fibonacci(int n);
long int fibonacci_optimised(int n,std::unordered_map<int,long int>* ptr=nullptr);

long int gridTraveller(int rows,int columns);

long int gridTraveller_optimised(int rows, int columns,std::unordered_map<std::string,long int>* pathMap=nullptr);

long int gridTraveller_withObstacles(std::vector<std::vector<char>>& matrix,int row,int column,std::unordered_map<std::string,long int>* gridObsMap=nullptr);

long int gridTraveller_shortestPathlength(std::vector<std::vector<char>> &matrix, int row, int column, std::unordered_map<std::string, long int> *gridObsMap=nullptr);
#endif