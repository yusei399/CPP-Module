#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class	RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		~RobotomyRequestForm();
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &rhs);
		void	execute(const Bureaucrat &executor) const;
	private:
		RobotomyRequestForm();
};

#endif
