#include "Form.hpp"

const char *Form::GradeTooHighException::what() const throw()
{
	return ("The grade is higer than the maximum possible grade(1)");
}

Form::GradeTooLowException::GradeTooLowException() : _msg("The grade is lower than the minimum possible grade (150).") {}


Form::GradeTooLowException::GradeTooLowException(const char *_msg) : _msg(_msg) {}

const char *Form::GradeTooLowException::what() const const throw()
{
	return (this->_msg);
}

Form::Form() : _name(), _sign_grade(1), _exce_grade(1), _signed(false) {}