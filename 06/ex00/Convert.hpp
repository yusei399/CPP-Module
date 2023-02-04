#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include "stdlib.h"

class Convert
{
	private:
    std::string _num;
	char _minus;
	std::string _Finfo;
	std::string _Dinfo;


	void converter(void);
	void convert_char();
	void convert_int();
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
};


#endif