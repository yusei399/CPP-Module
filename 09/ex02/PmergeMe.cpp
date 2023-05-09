#include "PmergeMe.hpp"

void PmergeMe_vec(std::vector<int> &value)
{
	std::sort(value.begin(), value.end());
}

void PmergeMe_deq(std::deque<int> &value)
{
	std::sort(value.begin(), value.end());
}