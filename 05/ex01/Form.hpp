#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"
#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat;

class Form
{
public:
	Form();
	Form(std::string,  const int, const int);
	Form(const Form &);
	~Form();

	Form &operator=(const Form &other);

	std::string getName(void) const;
	bool getIsSigned(void) const;
	int getReqSign(void) const;
	int getReqExe(void) const;
	void beSigned(const Bureaucrat &);
	static const int max_grade = 1; 
	static const int min_grade = 150;

private:
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class AlreadySignedException : public std::exception
	{
		virtual const char *what() const throw();
	};

	const std::string name_;
	bool is_signed_;
	const int req_sign_;
	const int req_exe_;
};

std::ostream &operator<<(std::ostream &, const Form &);

#endif 