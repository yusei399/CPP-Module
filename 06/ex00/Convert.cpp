#include "Convert.hpp"

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

Convert::Convert(){}

Convert::Convert(std::string num) : _num(num), _minus('\0'), _Finfo("f"){}

Convert::~Convert(){}

Convert &Convert::operator=(const Convert &rhs)
{
    (void)rhs;
    return (*this);
}

bool Convert::special_value()
{
    if (_num == "nan" || _num == "nanf")
    {
        std::cout << "char impossible" << std::endl;
        std::cout << "int impossible" << std::endl;
        std::cout << "float nanf" << std::endl;
        std::cout << "double nan" << std::endl;
        return true;
    }
    else if (_num == "+inf" || _num == "+inff")
    {
        std::cout << "char impossible" << std::endl;
        std::cout << "int impossible" << std::endl;
        std::cout << "float +inff" << std::endl;
        std::cout << "double ++inff" << std::endl;
        return true;
    }
    else if (_num == "-inf" || _num == "-inff")
    {
        std::cout << "char impossible" << std::endl;
        std::cout << "int impossible" << std::endl;
        std::cout << "float -inf" << std::endl;
        std::cout << "double -inff" << std::endl;
        return true;
    }
    return false;
}