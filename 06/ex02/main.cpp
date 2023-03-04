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
            std::cout << "Class A" << std::endl;
            return (new A());
        case 1:
            std::cout << "Class B" << std::endl;
            return (new B());
        default:
            std::cout << "Class C" << std::endl;
            return (new C());
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p)) {
        std::cout << "Object A" << std::endl;
        return;
    }
    if (dynamic_cast<B*>(p)) {
        std::cout << "Object B" << std::endl;
        return;
    }
    if (dynamic_cast<C*>(p)) {
        std::cout << "Object C" << std::endl;
        return;
    }

    std::cout << "unknown" << std::endl;
}

void identify(Base& p)
{
    try {
        static_cast<void>(dynamic_cast<A&>(p));
        std::cout << "Object A" << std::endl;
        return;
    } catch (std::exception&) {
    }
    try {
        static_cast<void>(dynamic_cast<B&>(p));
        std::cout << "Object B" << std::endl;
        return;
    } catch (std::exception&) {
    }
    try {
        static_cast<void>(dynamic_cast<C&>(p));
        std::cout << "Object C" << std::endl;
        return;
    } catch (std::exception&) {
    }

    std::cout << "unknown" << std::endl;
}

int main()
{
    for (size_t i = 0; i < 10; i++) {
        Base* ptr = generate();
        identify(ptr);
        identify(*ptr);
        std::cout << std::endl;
    }
}