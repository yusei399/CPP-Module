#include "Intern.hpp"
#include <ctime>

int	main()
{
	srand(time(0));

	Bureaucrat				Shogura("Shogura", 145);
	Bureaucrat				Yusei("Yusei", 137);
	Bureaucrat				Susui("Susui", 1);

	Intern	intern;

	AForm	*fshrub = intern.makeForm("shrubbery creation", "home");
	AForm	*frobo = intern.makeForm("robotomy request", "jjiojoi");
	AForm	*fpardon = intern.makeForm("presidential pardon", "guyguyg");
	AForm	*fnull = intern.makeForm("resurrection ritual", "Luci");

	std::cout << "fshrub located at " << fshrub << std::endl;
	std::cout << "frobo located at " << frobo << std::endl;
	std::cout << "fpardon located at " << fpardon << std::endl;
	std::cout << "fnull located at " << fnull << std::endl;

	std::cout << std::endl;

	Shogura.signForm(*fshrub);
	Yusei.executeForm(*fshrub);
	Susui.signForm(*frobo);
	Susui.executeForm(*frobo);
	Susui.signForm(*fpardon);
	Susui.executeForm(*fpardon);

	delete fshrub;
	delete frobo;
	delete fpardon;
}