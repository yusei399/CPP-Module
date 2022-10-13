#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException:: what() const throw()
{
	return ("The grade (1)");
}


const char *Bureaucrat::GradeTooLowException:: what() const throw()
{
	return (" The grade low (150)");
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) :_name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat() {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name), _grade(copy._grade) {}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &rhs)
{
	this->_grade = rhs._grade;
	return (*this);
}



