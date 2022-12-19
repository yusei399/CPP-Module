#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include "stdlib.h"

class Convert
{
	private:
		enum NumType {TypeChar, TypeInt, TypeFloat, TypeDouble };
	private:
    std::string value;
    char        c;
    int         num_int;
    double      numd;
    float       numf;
    NumType     type;
    bool        error;

	private:
	public:
		Convert();
		Convert(const Convert&);
		Convert(const std::string &value);
		Convert& operator=(const Convert&);
		~Convert();

		void parse();
		std::string to_char() const;
		std::string to_int() const;
		std::string to_float() const;
		std::string to_double() const;
};


#endif