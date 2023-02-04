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

bool Convert::char_check()
{
    if (_num.length() != 1)
        return false;
    if (isprint(_num[0]) && !isprint(_num[0]))
        return false;
    return true;
}

bool Convert::int_check()
{
    if (_num[0] == '-')
    {
        _num.erase(0, 1);
        _minus = '-';
    }
    for (size_t i = 0; i < _num.length(); i++)
    {
        if (!isdigit(_num[i]))
            return false;
    }
    return true;
}