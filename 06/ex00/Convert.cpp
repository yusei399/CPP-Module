#include "Convert.hpp"

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <cfloat>
#include <sstream>

Convert::Convert(){}

Convert::Convert(std::string num) : _num(num), _sign('\0'), _float_flag("f"){}

Convert::~Convert(){}

Convert &Convert::operator=(const Convert &rhs)
{
    (void)rhs;
    return (*this);
}

void Convert::impossible_message()
{
    std::cout << "char impossible" << std::endl;
    std::cout << "int impossible" << std::endl;
    std::cout << "float impossible" << std::endl;
    std::cout << "double impossible" << std::endl;
}

bool Convert::special_value()
{
    if (_num == "nan" || _num == "nanf" || _num == "+inf" || _num == "+inff" || _num == "-inf" || _num == "-inff")
    {
            std::cout << "char impossible" << std::endl;
            std::cout << "int impossible" << std::endl;
        if (_num == "nan" || _num == "nanf")
        {
            std::cout << "float nanf" << std::endl;
            std::cout << "double nan" << std::endl;
        }
        else if (_num == "+inf" || _num == "+inff")
        {
            std::cout << "float +inff" << std::endl;
            std::cout << "double ++inff" << std::endl;
            return true;
        }
        else if (_num == "-inf" || _num == "-inff")
        {
            std::cout << "float -inf" << std::endl;
            std::cout << "double -inff" << std::endl;
        }
    return true;
    }
    return false;
}

bool Convert::char_check()
{
    if (_num.length() != 1)
        return false;
    if (isprint(_num[0]) && !isdigit(_num[0]))
        return true;
    return false;
}

bool Convert::int_check()
{
    if (_num[0] == '-')
    {
        _num.erase(0, 1),
        _sign = '-';
    }
    for (size_t i = 0; i < _num.length(); i++)
    {
        if (!isdigit(_num[i]))
            return false;
    }
    return true;
}

bool Convert::float_check()
{
    int i = 0;

    if (!isdigit(_num[i]))
        return false;
    for (; isdigit(_num[i]); i++ ){}
    if (_num[i++] != '.')
        return false;
    if (!isdigit(_num[i]))
        return false;
    else if (_num[i] == '0')
        _float_flag = ".0f",_double_flag = ".0";
    for (; isdigit(_num[i]); i++){}
    if (_num[i++] != 'f')
        return false;
    if (_num[i])
        return false;
    return true;
}

bool Convert::double_check()
{
    int i = 0;
    if (_num[i] == '-')
        i++,_sign = '-';
    if (!isdigit(_num[i]))
        return false;
    for  (; isdigit(_num[i]); i++){}
    if (_num[i++] != '.' && isdigit(_num[i]))
        return false;
    else if (_num[i] == '0')
        _float_flag = ".0f",_double_flag = ".0";
    for  (; isdigit(_num[i]); i++){}
    if (_num[i])
        return false;
    return true;
}

void Convert::convert_char()
{
    char char_num = _num[0];
    int i = static_cast<int>(char_num);
    float f = static_cast<float>(char_num);
    double d = static_cast<double>(char_num);

    std::cout << "char" << char_num << std::endl;
    std::cout << "int" << i << std::endl;
    std::cout << "float" << f << std::endl;
    std::cout << "double" << d << std::endl;
}

void Convert::convert_int()
{
    double d = strtod(_num.c_str(), NULL);
    int i = static_cast<int>(d);
    char ch = static_cast<char>(d);
    float f = static_cast<float>(d);

    if (isprint(ch) && 0 < d && d < 256)
        std::cout << "char:" << ch << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl; 
    
    if (d == 0)
    {
        std::cout << "int:" << i << std::endl;
        std::cout << "float:" << f << ".0f" <<std::endl;
        std::cout << "double:" << d << ".0" <<std::endl; 
    }
    else if (d <= INT_MAX && d >= INT_MIN)
    {
        std::cout << "int:"<< _sign << i << std::endl;
        std::cout << "float:" << _sign << f << ".0f" <<std::endl;
        std::cout << "double:" << _sign << d << ".0" <<std::endl;
    }
    else
    {
        std::cout << "int: int overflow" << std::endl;
        std::cout << "float: int overflow" << std::endl;
        std::cout << "double: int overflow" << std::endl;
    }
}

void Convert::convert_float()
{
    double d = strtod(_num.c_str(), NULL);
    int  i = static_cast<int>(d);
    char ch = static_cast<char>(d);
    float f = static_cast<float>(d);

    if (isprint(ch) && d < 256 &&  d > 0)
        std::cout << "char:" << ch << std::endl;
    else
        std::cout << "char : Non displayable" << std::endl;
    if (d == 0)
    {
        std::cout << "int:" << i << std::endl;
        std::cout << "float:" << f << ".0f" <<std::endl;
        std::cout << "double:" << d << ".0" <<std::endl;  
    }
    else if (d <= FLT_MAX  && d >= FLT_MIN)
    {
        if (d <= INT_MAX && d >= INT_MIN)
            std::cout << "int:" << _sign << i << std::endl;
        else
            std::cout << "int : int overflow" << std::endl;
        std::cout << "float:" << _sign << f << _float_flag << std::endl;
        std::cout << "double:" << _sign << d << _double_flag <<std::endl;
    }
    else
    {
        std::cout << "int: float overflow" << std::endl;
        std::cout << "float: float overflow" << std::endl;
        std::cout << "double: float overflow" << std::endl;
    }
} 

void Convert::convert_double()
{
    double d = strtod(_num.c_str(), NULL);
    int i = static_cast<int>(d);
    char ch = static_cast<char>(d);
    float f = static_cast<float>(d);
    
    if (isprint(ch) && 0 < d && d < 256)
        std::cout << "char:" << ch << std::endl;
    else
        std::cout << "non displayable" << std::endl;
    if (d <= INT_MAX && d >= INT_MIN)
    {
        if (d != 0)
            std::cout << "int: " << _sign << i << std::endl;
        else
            std::cout << "int:" <<  "0.0" << std::endl;
    }
    else
            std::cout << "int overflow" << std::endl;
    if (d == 0)
            std::cout << "float:" << "0.0f" << std::endl;
    else if (d <= FLT_MAX && d >= FLT_MIN)
            std::cout << "float:"<< _sign << f << _float_flag << std::endl;
    else
            std::cout << "float : overflow" << std::endl;
    if (d != 0)
        std::cout << "double:" << _sign << d << _double_flag << std::endl;
    else
        std::cout << "double:" << "0.0" << std::endl;
}

void Convert::converter()
{
    if (!special_value())
    {
        if (char_check())
            convert_char();
        else if (int_check())
            convert_int();
        else if (float_check())
            convert_float();
        else if (double_check())
            convert_double();
        else
            impossible_message();
    }
    return ;
}
