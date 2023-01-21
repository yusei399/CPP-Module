#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <string>

class	AForm
{
	private:
		const std::string	_name;
		std::string			_target;
		const int			_sign_grade;
		const int			_exec_grade;
		bool				_signed;
		static const int max_grade = 1; 
		static const int min_grade = 150;
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
		class	ExecutingUnsignedFormException : public std::exception
		{			
			public:
				virtual const char *what() const throw();
		};
	protected:
		AForm();
		AForm(const std::string &name, const std::string &target, int sign_grade, int exec_grade);
		AForm(const AForm &copy);
		bool			check_executor(const Bureaucrat &executor) const;
	public:
		virtual ~AForm();
		AForm				&operator=(const AForm &rhs);
		const std::string	&getName() const;
		const std::string	&getTarget() const;
		int					getSignGrade() const;
		int					getExecutionGrade() const;
		bool				isSigned() const;
		void				beSigned(const Bureaucrat &bureaucrat);
		virtual void		execute(const Bureaucrat &executor) const = 0;
};

std::ostream	&operator<<(std::ostream &o, const AForm &f);

#endif