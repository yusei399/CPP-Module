#include "PmergeMe.hpp"

void PmergeMe_vec(std::vector<int> &value)
{
	if (value.size() > 1)
	{
		std::vector<int> left;
		std::vector<int> right;

		for (size_t i = 0; i < value.size() / 2; i++)
			left.push_back(value[i]);
		
		for (size_t i = value.size() / 2; i < value.size(); i++)
			right.push_back(value[i]);
		
		for (size_t i = 0; i < left.size(); i++)
        {
            int j = i;
            while (j > 0 && left[j] < left[j - 1])
            {
                std::swap(left[j], left[j - 1]);
                j--;
            }
        }

		for (size_t i = 0; i < right.size(); i++)
		{
			if (right[i] > right[i + 1])
				std::swap(right[i], right[i + 1]);
		}

		for (size_t i = 0; i < right.size(); i++)
        {
            std::vector<int>::iterator it = std::lower_bound(left.begin(), left.end(), right[i]);
            left.insert(it, right[i]);
        }

        for (size_t i = 0; i < value.size(); i++)
			value[i] = left[i];
	}
}

void PmergeMe_deq(std::deque<int> &value)
{
	std::sort(value.begin(), value.end());
}