
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>

int	main()
{
	srand(time(0));
	ShrubberyCreationForm	shrubbery("PlanetExpress");
	RobotomyRequestForm		robotomy("Bender");
	PresidentialPardonForm	presidential("Turanga Leela");

	Bureaucrat				Yusei("Yusei", 145);
	Bureaucrat				Eiki("Eiki", 137);
	Bureaucrat				Susui("Susui", 1);

	std::cout << Yusei << std::endl << Eiki << std::endl << Susui << std::endl;
	std::cout << shrubbery << std::endl;
	Susui.executeForm(shrubbery);
	Yusei.signForm(shrubbery);
	Yusei.executeForm(shrubbery);
	Eiki.executeForm(shrubbery);
	Susui.executeForm(shrubbery);
	std::cout << shrubbery << std::endl;

	std::cout << std::endl;

	std::cout << robotomy << std::endl;
	Eiki.signForm(robotomy);
	Susui.signForm(robotomy);
	Susui.executeForm(robotomy);
	Susui.executeForm(robotomy);
	Susui.executeForm(robotomy);

	std::cout << std::endl;

	std::cout << presidential << std::endl;
	Susui.signForm(presidential);
	Susui.executeForm(presidential);
}