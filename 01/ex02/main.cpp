#include <string>
#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";

	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Address from the object: " << &str << std::endl;
	std::cout << "Address from the pointer: " << stringPTR << std::endl;
	std::cout << "Address from the reference: " << &stringREF << std::endl;

	std::cout << "Value from the object: " << str << std::endl;
	std::cout << "Value from the pointer: " << *stringPTR << std::endl;
	std::cout << "Value from the reference: " << stringREF << std::endl;
}