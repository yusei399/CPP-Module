#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain create" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destroy" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << " Brain copy" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
}

Brain	&Brain::operator=(const Brain &rhs)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = rhs.ideas[i];
	return (*this);
}
