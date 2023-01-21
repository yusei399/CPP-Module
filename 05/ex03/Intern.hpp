# ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern&);
		~Intern();
		Intern &operator=(const Intern&);
		AForm	*makeForm(const std::string &name, const std::string &target) const;
	private:
		AForm	*makePresidentialPardon(const std::string &target) const;
		AForm	*makeRobotomyRequest(const std::string &target) const;
		AForm	*makeShrubberyCreation(const std::string &target) const;
};

#endif
