#include "AForm.hpp"

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("The grade is higher than the maximum possible grade (1).");
}

AForm::GradeTooLowException::GradeTooLowException() : _msg("The grade is lower than the minimum possible grade (150).") {}

AForm::GradeTooLowException::GradeTooLowException(const char *_msg) : _msg(_msg) {}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return (this->_msg);
}

const char	*AForm::ExecutingUnsignedFormException::what() const throw()
{
	return ("Cannot execute an unsigned form.");
}

AForm::AForm() : _name(), _target(), _sign_grade(1), _exec_grade(1), _signed(false) {}

AForm::AForm(const std::string &name, const std::string &target, int sign_grade, int exec_grade)
: _name(name), _target(target), _sign_grade(sign_grade), _exec_grade(exec_grade), _signed(false)
{
	if (sign_grade < max_grade || exec_grade < max_grade)
		throw GradeTooHighException();
	else if (sign_grade > min_grade || exec_grade > min_grade)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &copy) : _name(copy._name), _target(copy._target), _sign_grade(copy._sign_grade),
_exec_grade(copy._exec_grade), _signed(copy._signed) {}

AForm::~AForm() {}

AForm	&AForm::operator=(const AForm &rhs)
{
	if (this == &rhs)
		return (*this);
	else
	{
		this->_signed = rhs._signed;
		this->_target = rhs._target;
		return (*this);
	}
}

const std::string	&AForm::getName(void) const
{
	return (this->_name);
}

const std::string	&AForm::getTarget(void) const
{
	return (this->_target);
}

int	AForm::getSignGrade(void) const
{
	return (this->_sign_grade);
}

int	AForm::getExecutionGrade(void) const
{
	return (this->_exec_grade);
}

bool	AForm::isSigned(void) const
{
	return (this->_signed);
}

std::ostream	&operator<<(std::ostream &o, const AForm &f)
{
	o << "Form `" << f.getName() << "`, ";
	if (!f.isSigned())
		o << "not ";
	o << "signed, targeting " << f.getTarget() << ", requires Grade " << f.getSignGrade() << " to sign and " << f.getExecutionGrade() << " to execute";
	return (o);
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_sign_grade)
		throw GradeTooLowException("Bureaucrat is not authorized to sign due to their grade being too low");
	this->_signed = true;
}

bool	AForm::check_executor(const Bureaucrat &executor) const
{
	if (executor.getGrade() > this->_exec_grade)
		throw GradeTooLowException("Bureaucrat is not authorized to sign due to their grade being too low");
	if (!this->_signed)
		throw ExecutingUnsignedFormException();
	return true;
}
