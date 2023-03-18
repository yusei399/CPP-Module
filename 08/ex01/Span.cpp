#include "Span.hpp"

Span::Span() : _size(0)
{
}

Span::Span(const Span &other)
{
	*this = other;
}

Span::Span(unsigned int num) : _size(num)
{
}

Span::~Span()
{
}

Span &Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		this->_size = rhs._size;
		this->_num = rhs._num;
	}
	return (*this);
}

void	Span::addNumber(long num)
{
	if (this->_num.size() == this->_size)
		throw std::exception();
	this->_num.push_back(num);
}

void	Span::addNumber(std::vector<int> &num)
{
	if (this->_num.size() + num.size() > this->_size)
		throw std::exception();
	for (size_t i = 0; i < num.size(); i++)
		this->_num.push_back(num[i]);
}

long	Span::shortestSpan()
{
	if (this->_num.size() < 2)
		throw std::exception();
	std::vector<long> tmp = this->_num;
	std::sort(tmp.begin(), tmp.end());
	long min = tmp[1] - tmp[0];
	for (size_t i = 2; i < tmp.size(); i++)
	{
		if (tmp[i] - tmp[i - 1] < min)
			min = tmp[i] - tmp[i - 1];
	}
	return (min);
}

long	Span::longestSpan()
{
	if (this->_num.size() < 2)
		throw std::exception();
	std::vector<long> tmp = this->_num;
	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}
