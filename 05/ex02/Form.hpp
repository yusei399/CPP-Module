#ifndef FORM_HPP
# define FORM_HPP
#include <iostream>
#include <string>

#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string _name;
	const int _sign_grade;
	const int _exec_grade;
	bool  _signed;
	class	GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class	GradeTooLowException : public std::exception
	{
		private:
			const char	*_msg;
		public:
			GradeTooLowException();
			GradeTooLowException(const char *_msg);
			virtual const char *what() const throw();
	};
	protected:
	Form();
		Form(const std::string &name, const std::string &target, int sign_grade, int exec_grade);
		Form(const Form &copy);
		void				check_executor(const Bureaucrat &executor) const;

public:
	Form(const std::string &name, int sign_grade, int exec_grade);
	Form(const Form &copy);
	const std::string	&getName() const;
	const std::string	&getTarget() const;
	~Form();
	Form	&operator=(const Form &rhs);
	const std::string &getName();
	const std::string	&getName() const;
	int					getSignGrade() const;
	int					getExecutionGrade() const;
	bool				isSigned() const;
	void				beSigned(const Bureaucrat &bureaucrat);
};

std::ostream	&operator<<(std::ostream &o, const Form &f);

#endif