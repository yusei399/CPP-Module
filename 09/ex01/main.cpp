#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <exception>

bool is_operator(char op)
{
	if (op == '+' || op == '-' || op == '*' || op == '/')
		return (true);
	return (false);
}


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./rpn \"expression\"" << std::endl;
		return (1);
	}
	std::stack<int> num;
	std::string op_token;
	std::istringstream iss(argv[1]);

	while (iss >> op_token)
	{
		if (op_token == "+" || op_token == "-" || op_token == "*" || op_token == "/")
		{
			if (num.size() < 2)
			{
				std::cout << "Error: not enough operators" << std::endl;
				return (1);
			}
			int num2 = num.top(); num.pop();
			int num1 = num.top(); num.pop();
			if (op_token == "+")
				num.push(num1 + num2);
			else if (op_token == "-")
				num.push(num1 - num2);
			else if (op_token == "*")
				num.push(num1 * num2);
			else if (op_token == "/")
			{
				if (num2 == 0)
				{
					std::cout << "Error: division by zero" << std::endl;
					return (1);
				}
				num.push(num1 / num2);
			}
		}
		else
		{
			for(int i=0; op_token[i] !='\0'; i++) {
				if(!isdigit(op_token[i])) {
					std::cout << "Error: bad input." << std::endl;
					return 1;
				}
			}
			num.push(atoi(op_token.c_str()));
		}
		std::cout << "num: " << num.top() << std::endl;
	}
	if (num.size() != 1)
	{
		std::cerr << "Error: not enough operators" << std::endl;
		return (1);
	}
	std::cout << num.top() << std::endl;
	return (0);
}
