#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cctype>

int main(int argc, char **argv)
{
    std::vector<int> v;
    // std::deque<int> d;
    if (argc < 2)
    {
        std::cerr << "Usage: ./PmergeMe [value1] [value2] ..." << std::endl;
        return (1);
    }
    for (int i = 1; i < argc; i++)
    {
        for (int j = 0; argv[i][j] != '\0'; j++)
        {
            if (isdigit(argv[i][j]) == 0)
            {
                std::cerr << "Error: bad input." << std::endl;
                return (1);
            }
        }
    }

    for (int i = 1; i < argc; i++)
        v.push_back(atoi(argv[i]));

    // for (int i = 1; i < argc; i++)
    //     d.push_back(atoi(argv[i]));

    std::cout << "Before: ";
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    clock_t start, end;
    start = clock();
    PmergeMe_vec(v);
    end = clock();

    std::cout << "After:  ";
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Time to process a range of " << v.size() << " elements with std::vector: "
              << std::fixed << std::setprecision(5) << cpu_time_used << " us." << std::endl;

    return 0;
}
