
#include "Convert.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		class Convert	type(argv[1]);
		
		type.parse();
	}
	else
		std::cerr << "Invalid arg" << std::endl;
	return 0;
}