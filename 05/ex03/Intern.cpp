#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern&) {}

Intern &Intern::operator=(const Intern&) {return (*this); }

AForm	*Intern::makePresidentialPardon(const std::string &target) const
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeRobotomyRequest(const std::string &target) const
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makeShrubberyCreation(const std::string &target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeForm(const std::string &name, const std::string &target) const
{
	AForm *(Intern::*forms[])(const std::string&) const =
	{
		&Intern::makePresidentialPardon,
		&Intern::makeRobotomyRequest,
		&Intern::makeShrubberyCreation
	};
	const char	*forms_names[] =
	{
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};
	for (size_t i = 0; i < 3; i++)
		if (name == forms_names[i])
			return ((this->*forms[i])(target));
	std::cout << "Intern was requested an unknown form" << std::endl;
	return (NULL);
}