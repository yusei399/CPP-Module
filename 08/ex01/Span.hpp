#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>

class Span
{
private:
	unsigned int size_;
	std::vector<long> num_;
public:
	Span();
	Span(unsigned int num);
	~Span();

	Span(const Span &);
	Span &operator=(const Span &);

	void	addNumber(long);
	void	addNumber(std::vector<int> &);
	long	shortestSpan();
	long	longestSpan();
};


#endif