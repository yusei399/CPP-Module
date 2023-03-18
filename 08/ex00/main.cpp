#include <deque>
#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"

int main()
{
    std::cout << " -----------------VECTOR----------------- "<< std::endl;
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    test_vetor(v, 1);
}