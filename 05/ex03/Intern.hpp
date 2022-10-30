# ifndef INTERN_HPP
# define INTERN_HPP

#include "Form.hpp"
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
		Form	*makeForm(const std::string &name, const std::string &target) const;
	private:
		Form	*makePresidentialPardon(const std::string &target) const;
		Form	*makeRobotomyRequest(const std::string &target) const;
		Form	*makeShrubberyCreation(const std::string &target) const;
};

#endif
