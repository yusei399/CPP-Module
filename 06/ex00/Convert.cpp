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

