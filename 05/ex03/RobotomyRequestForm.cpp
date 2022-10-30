#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form("robotomy request", target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : Form(copy) {}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	this->check_executor(executor);
	std::cout << "* bzzzzzzz... * " << this->getTarget() << " has been robotomized " << (rand() % 2 ? "successfully" : "UNsuccessfully") << std::endl;
}

