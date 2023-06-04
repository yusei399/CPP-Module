#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cctype>

void printErrorMessage(const std::string& message) {
    std::cerr << "Error: " << message << std::endl;
}

void printVector(const std::vector<int>& v) {
    std::cout << "Before: ";
    for (size_t i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}

void printDeque(const std::deque<int>& d) {
    std::cout << "Before: ";
    for (size_t i = 0; i < d.size(); i++)
        std::cout << d[i] << " ";
    std::cout << std::endl;
}

void printProcessingTime(const std::string& containerName, size_t size, double cpuTime) {
    std::cout << "Time to process a range of " << size << " elements with " << containerName << ": "  
        << std::fixed << std::setprecision(5) << cpuTime << " us." << std::endl;
}

bool validateInputArguments(int argc, char **argv) {
    if (argc < 2) {
        printErrorMessage("Usage: ./PmergeMe [value1] [value2] ...");
        return false;
    }

    for (int i = 1; i < argc; i++) {
        for (int j = 0; argv[i][j] != '\0'; j++) {
            if (!std::isdigit(argv[i][j])) {
                printErrorMessage("bad input.");
                return false;
            }
        }
    }

    return true;
}

void processVector(const std::vector<int>& v) {
    std::vector<int> vCopy = v;
    clock_t start, end;
    start = clock();
    PmergeMe_vec(vCopy);
    end = clock();

    printVector(vCopy);

    double cpuTimeUsed = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000;
    printProcessingTime("std::vector", v.size(), cpuTimeUsed);
}

void processDeque(const std::deque<int>& d) {
    std::deque<int> dCopy = d;
    clock_t start, end;
    start = clock();
    PmergeMe_deq(dCopy);
    end = clock();

    printDeque(dCopy);

    double cpuTimeUsed = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000;
    printProcessingTime("std::deque", d.size(), cpuTimeUsed);
}

int main(int argc, char **argv) {
    if (!validateInputArguments(argc, argv)) {
        return 1;
    }

    std::vector<int> v;
    std::deque<int> d;

    for (int i = 1; i < argc; i++) {
        v.push_back(std::atoi(argv[i]));
    }

    for (int i = 1; i < argc; i++) {
        d.push_back(std::atoi(argv[i]));
    }

    std::cout << "Before: ";
    printVector(v);

    processVector(v);

    std::cout << "Before: ";
    printDeque(d);

    processDeque(d);

    return 0;
}

