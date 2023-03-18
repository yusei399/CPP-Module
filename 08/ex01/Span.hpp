#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>

class Span
{
private:
	unsigned int _size;
	std::vector<long> _num;
public:
	Span();
	Span(unsigned int num);
	~Span();
	Span(const Span &other);
	Span &operator=(const Span &rhs);

	void	addNumber(long);
	void	addNumber(std::vector<int> &);
	long	shortestSpan();
	long	longestSpan();
};


#endif