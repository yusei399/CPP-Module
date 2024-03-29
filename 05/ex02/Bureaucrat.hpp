#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class	AForm;

class	Bureaucrat
{
	public:
		Bureaucrat(const std::string &name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat	&operator=(const Bureaucrat &rhs);
		const std::string	&getName() const;
		int					getGrade() const;
		void				signForm(AForm &form) const;
		void				executeForm(const AForm &form);
		void				promote();
		void				demote();
	private:
		Bureaucrat();
		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		const std::string	_name;
		int					_grade;
};

# include "AForm.hpp"

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &b);

#endif