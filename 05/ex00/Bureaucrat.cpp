#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("unknown"), grade_(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name_(name), grade_(grade)
{
	if (grade > 150)
		throw(Bureaucrat::GradeTooLowException());
	else if (grade < 1)
		throw(Bureaucrat::GradeTooHighException());
}

Bureaucrat::Bureaucrat(const Bureaucrat &o)
{
	*this = o;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &o)
{
	this->grade_ = o.grade_;

	return *this;
}

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &instance)
{
	stream << instance.getName() << ", bureaucrat grade" << instance.getGrade() << "";

	return stream;
}

std::string Bureaucrat::getName(void) const
{
	return this->name_;
}

