#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

#define MAX_GRADE 1
#define MIN_GRADE 150
#define HighException "Grade is too high"
#define LowException "Grade is too low"

class Form;

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(std::string, int);
	Bureaucrat(const Bureaucrat &);
	~Bureaucrat();

	Bureaucrat &operator=(const Bureaucrat &);

	void incrementGrade(void);
	void decrementGrade(void);

	std::string getName(void) const;
	int getGrade(void) const;

	void signForm(Form &) const;

private:
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};

	const std::string name_;
	int grade_;
};

std::ostream &operator<<(std::ostream &, const Bureaucrat &);

#endif