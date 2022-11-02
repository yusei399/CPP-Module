#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <iostream>

template <typename T>
void swap(T &arg1, T &arg2)
{
	T tmp;

	tmp = arg1;
	arg1 = arg2;
	arg2 = tmp;
}

template<typename T>
T &min(T &arg1, T &arg2)
{
	if (arg1 < arg2)
		return arg1;
	return arg2;
}

template<typename T>
T &max(T &arg1, T &arg2)
{
	if (arg1 > arg2)
		return arg1;
	return arg2;
}

#endif