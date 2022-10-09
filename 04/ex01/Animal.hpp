#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class	Animal
{
	public:
		Animal();
		virtual ~Animal();
		Animal(const Animal &copy);
		Animal	&operator=(const Animal &rhs);
		const std::string	&getType() const;
		virtual void		makeSound() const;
	protected:
		Animal(const std::string &type);
		std::string	type;
};

#endif