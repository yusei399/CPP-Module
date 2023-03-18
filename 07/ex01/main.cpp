#include "iter.hpp"
#include <iostream>

template <typename T>
void	print1(const T &x)
{
	std::cout << x << std::endl;
}

void	print2(const int &x)
{
	std::cout << x << std::endl;
}

int	main()
{
	int	array[] = {1, 2, 3, 4, 5};
	std::cout << "print1 :" << std::endl;
	iter(array, 5, print1);
	std::cout << "print2:" << std::endl;
	iter(array, 5, print2);
}
