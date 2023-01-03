#ifndef IMATERIASOUCE_HPP
#define IMATERIASOUCE_HPP

#include "AMateria.hpp"
#include <string>

class IMateriaSource
{
public:
	virtual ~IMateriaSource(){};
	virtual void learnMateria(AMateria *) = 0;
	virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif // IMATERIASOUCE_HPP
