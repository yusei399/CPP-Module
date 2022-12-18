#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream> 

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