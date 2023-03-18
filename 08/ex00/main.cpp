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
    test_vetor(v, 2);
    test_vetor(v, 3);
    test_vetor(v, 4);
    test_vetor(v, 5);
    test_vetor(v, 6);

    std::cout << " -----------------LIST----------------- "<< std::endl;
    std::list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    test_list(l, 1);
    test_list(l, 2);
    test_list(l, 3);
    test_list(l, 4);
    test_list(l, 5);
    test_list(l, 6);
}