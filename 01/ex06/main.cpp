#include "Harl.hpp"

enum	e_level
{
	debug,
	info,
	warning,
	error,
	undefined
};

e_level	ft_interpret_complaint(const std::string &level)
{
	if (level == "DEBUG")
		return (debug);
	else if (level == "INFO")
		return (info);
	else if (level == "WARNING")
		return (warning);
	else if (level == "ERROR")
		return (error);
	return (undefined);
}

int main(int argc, char **argv)
{
	Harl	harl;

	if (argc != 2)
		harl.complain("You provided wrong number of arguments. Why should I complain when"
			" you give me the incorrect number of arguments?! This is outrageous.");
	else
	{
		std::string	level = argv[1];
		e_level		enumerated_level = ft_interpret_complaint(level);
		switch (enumerated_level)
		{
			case debug:
				harl.complain("debug");
			case info:
				harl.complain("info");
			case warning:
				harl.complain("warning");
			case error:
				harl.complain("error");
				break ;
			default:
				harl.complain("masks, vaccinations, gays, lockdown etc..");
		}
	}
}