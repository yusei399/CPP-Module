#include "Span.hpp"

Span::Span() : size_(0)
{
}

Span::Span(const Span &other)
{
	*this = other;
}

Span::~Span()
{
}

