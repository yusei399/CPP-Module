
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <exception>
#include <limits>
#include <cstdlib>

bool is_operator(char op)
{
    if (op == '+' || op == '-' || op == '*' || op == '/')
        return true;
    return false;
}

bool is_operator(const std::string& op)
{
    if (op == "+" || op == "-" || op == "*" || op == "/")
        return true;
    return false;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./rpn \"expression\"" << std::endl;
        return 1;
    }

    std::stack<int> num;
    std::string op_token;
    std::istringstream iss(argv[1]);

    while (iss >> op_token)
    {
        if (is_operator(op_token))
        {
            if (num.size() < 2)
            {
                std::cout << "Error: not enough operators" << std::endl;
                return 1;
            }
            int num2 = num.top();
            num.pop();
            int num1 = num.top();
            num.pop();
            if (op_token == "+")
            {
                if ((num2 > 0 && num1 > std::numeric_limits<int>::max() - num2) || (num2 < 0 && num1 < std::numeric_limits<int>::min() - num2))
                {
                    std::cout << "Error: integer overflow" << std::endl;
                    return 1;
                }
                num.push(num1 + num2);
            }
            else if (op_token == "-")
            {
                if ((num2 > 0 && num1 < std::numeric_limits<int>::min() + num2) || (num2 < 0 && num1 > std::numeric_limits<int>::max() + num2))
                {
                    std::cout << "Error: integer overflow" << std::endl;
                    return 1;
                }
                num.push(num1 - num2);
            }
            else if (op_token == "*")
            {
                if ((num2 > 0 && (num1 > std::numeric_limits<int>::max() / num2 || num1 < std::numeric_limits<int>::min() / num2)) || (num2 < 						0 && (num1 < std::numeric_limits<int>::max() / num2 || num1 > std::numeric_limits<int>::min() / num2)))
                {
                    std::cout << "Error: integer overflow" << std::endl;
                    return 1;
                }
                num.push(num1 * num2);
            }
            else if (op_token == "/")
            {
                if (num2 == 0)
                {
                    std::cout << "Error: division by zero" << std::endl;
                    return 1;
                }
                num.push(num1 / num2);
            }
        }
        else
        {
            if (op_token[0] == '-' && op_token.size() > 1)
            {
                std::string num_str = op_token.substr(1);
                for (size_t i = 0; i < num_str.size(); i++)
                {
                    if (!isdigit(num_str[i]))
                    {
                        std::cout << "Error: bad input." << std::endl;
                        return 1;
                    }
                }
				long long value = std::strtoll(num_str.c_str(), NULL, 10);

                if (-value < std::numeric_limits<int>::min() || -value > std::numeric_limits<int>::max())
                {
                    std::cout << "Error: integer overflow" << std::endl;
                    return 1;
                }
                num.push(-static_cast<int>(value));
            }
            else
            {
                for (size_t i = 0; i < op_token.size(); i++)
                {
                    if (!isdigit(op_token[i]))
                    {
                        std::cout << "Error: bad input." << std::endl;
                        return 1;
                    }
                }
                long long value = std::strtoll(op_token.c_str(), NULL, 10);

                if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
                {
                    std::cout << "Error: integer overflow" << std::endl;
                    return 1;
                }
                num.push(static_cast<int>(value));
            }
        }
    }

    if (num.size() == 1)
    {
        std::cout << num.top() << std::endl;
        return 0;
    }
    else
    {
        std::cout << "Error: not enough operators" << std::endl;
        return 1;
    }
}