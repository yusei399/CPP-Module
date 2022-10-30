#include "Convert.hpp"

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

Convert::Convert()
    : value("0"), c(0), num_int(0), numd(0.0), numf(0.0f), type(TypeChar), error(true)
{
}

Convert::Convert(const Convert& other)
{
	*this = other;
}

Convert::Convert(const std::string& value_)
	: value(value_), c(0), num_int(0), numd(0.0), numf(0.0f), type(TypeChar), error(true)
{
	parse();
}

Convert& Convert::operator=(const Convert& rhs)
{
	value = rhs.value;
    c = rhs.c;
    num_int = rhs.num_int;
    numd = rhs.numd;
    numf = rhs.numf;
    type = rhs.type;
    error = rhs.error;

    return *this;
}

Convert::~Convert() {}

bool is_pseudo_litteral(const std::string& str)
{
    if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" ||
        str == "-inff" || str == "inf" | str == "inff") {
        return true;
    }
    return false;
}
