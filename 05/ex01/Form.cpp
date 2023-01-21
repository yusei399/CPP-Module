
#include "Form.hpp"

Form::Form() : name_("unknown"), is_signed_(false), req_sign_(MIN_GRADE), req_exe_(MIN_GRADE)
{
}

Form::Form(std::string name, const int req_sign, const int req_exe) : name_(name), is_signed_(false), req_sign_(req_sign), req_exe_(req_exe)
{
	if (req_sign > min_grade || req_exe > min_grade)
		throw(Form::GradeTooLowException());
	else if (req_sign < max_grade || req_exe < max_grade)
		throw(Form::GradeTooHighException());
}

Form::Form(const Form &other) : req_sign_(other.req_sign_), req_exe_(other.req_exe_)
{
	*this = other;
}

Form::~Form()
{
}

Form &Form::operator=(const Form &other)
{
	(void)other;
	return *this;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return HighException;
}

const char *Form::GradeTooLowException::what() const throw()
{
	return LowException;
}

const char *Form::AlreadySignedException::what() const throw()
{
	return "this form is already signed";
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > req_sign_)
		throw (Form::GradeTooLowException());
	else if (is_signed_ == true)
		throw(Form::AlreadySignedException());
	is_signed_ = true;
}

std::string Form::getName(void) const
{
	return name_;
}

bool Form::getIsSigned(void) const
{
	return is_signed_;
}

int Form::getReqSign(void) const
{
	return req_sign_;
}

int Form::getReqExe(void) const
{
	return req_exe_;
}

std::ostream &operator<<(std::ostream &stream, const Form &F)
{
	stream << F.getName() << ", is_signed " << F.getIsSigned() << ", req_sign " << F.getReqSign() << ", req_exe " << F.getReqExe();

	return stream;
}
