#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include "stdlib.h"

class Convert
{
	private:
    std::string _num;
	char _sign;
	std::string _float_flag;
	std::string _double_flag;


	void convert_char();
	void convert_int();
	void convert_float();
	void convert_double();
	void impossible_message();
	bool char_check();
	bool float_check();
	bool double_check();
	bool int_check();
	bool special_value();

	public:
		Convert();
		Convert(std::string num);
		Convert(const Convert&);
		~Convert();
		Convert& operator=(const Convert&);
		void converter(void);
};


#endif