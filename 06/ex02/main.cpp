#include <cstdlib>
#include <ctime>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

Base *generate()
{
	int random = rand() % 3;

	switch (random)
	{
        case 0:
            std::cout << "generate A class" << std::endl;
            return (new A());
        case 1:
            std::cout << "generate B class" << std::endl;
            return (new B());
        default:
            std::cout << "generate C class" << std::endl;
            return (new C());
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p)) {
        std::cout << "A  Object\n";
        return;
    }
    if (dynamic_cast<B*>(p)) {
        std::cout << "B  Object\n";
        return;
    }
    if (dynamic_cast<C*>(p)) {
        std::cout << "C  Object\n";
        return;
    }

    std::cout << "Can't identify\n";
}

void identify(Base& p)
{
    try {
        static_cast<void>(dynamic_cast<A&>(p));
        std::cout << "A Object \n";
        return;
    } catch (std::exception&) {
    }
    try {
        static_cast<void>(dynamic_cast<B&>(p));
        std::cout << "B  Object\n";
        return;
    } catch (std::exception&) {
    }
    try {
        static_cast<void>(dynamic_cast<C&>(p));
        std::cout << "C  Object\n";
        return;
    } catch (std::exception&) {
    }

    std::cout << "Can't identify\n";
}

int main()
{
    srand(static_cast<unsigned int>(time(NULL)));

    for (size_t i = 0; i < 5; i++) {
        Base* ptr = generate();
        identify(ptr);
        identify(*ptr);

        if (i < 4) {
            std::cout << "\n";
        }
    }
}