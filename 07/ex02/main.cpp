#include "Array.hpp"
#include <iostream>

int	main()
{
	Array<int>	hi;

	std::cout << "hi's size: " << hi.size() << std::endl;

	Array<int>	hello(20);
	Array<int>	bye(5);

	for (int i = 0; i < bye.size(); i++)
		bye[i] = i;
	for (int i = 0; i < hello.size(); i++)
		hello[i] = -i;

	Array<int>	no(bye);
	
	std::cout << "bye:";
	for (int i = 0; i < bye.size(); i++)
		std::cout << " " << bye[i];
	std::cout << std::endl << "hello: ";
	for (int i = 0; i < hello.size(); i++)
		std::cout << " " << hello[i];
	std::cout << std::endl << "no: ";
	for (int i = 0; i < no.size(); i++)
		std::cout << " " << no[i];
	bye = hello;
	std::cout << std::endl << "bye after \"bye = hello;\":";
	for (int i = 0; i < bye.size(); i++)
		std::cout << " " << bye[i];
	hello = no;
	std::cout << std::endl << "hello after \"hello = no;\":";
	for (int i = 0; i < hello.size(); i++)
		std::cout << " " << hello[i];
}
