#include<unordered_map>
#include<string>
long int fibonacci(int n);
long int fibonacci_optimised(int n,std::unordered_map<int,long int>* ptr=nullptr);

long int gridTraveller(int rows,int columns);

long int gridTraveller_optimised(int rows, int columns,std::unordered_map<std::string,long int>* pathMap=nullptr);
