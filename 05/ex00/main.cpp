#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat personA("A", 1);
		std::cout << personA << std::endl;
		std::cout << personA.getGrade() << std::endl;
		std::cout << personA.getName() << std::endl;
		personA.incrementGrade();
		std::cout << personA << std::endl;
		personA.decrementGrade();
		std::cout << personA << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat personB("B", 151);
		std::cout << personB << std::endl;
		std::cout << personB.getGrade() << std::endl;
		std::cout << personB.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat personC("C", 0);
		std::cout << personC << std::endl;
		std::cout << personC.getGrade() << std::endl;
		std::cout << personC.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}