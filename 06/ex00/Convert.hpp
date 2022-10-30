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
		void parse();
	public:
		Convert(std::string &inpput);
		Convert(Convert const &copy);
		Convert& operator=(const Convert&);
		~Convert();


		std::string to_char();
		std::string to_int();
		std::string to_float() const;
		std::string to_double() const;
};


#endif