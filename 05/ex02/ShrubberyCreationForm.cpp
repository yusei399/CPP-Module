#include "ShrubberyCreationForm.hpp"


const char *ShrubberyCreationForm::asciiTree =
	"		    *\n"
	"		   *-*\n"
	"		  *---*\n"
	"		 *-----*\n"
	"		*-------*\n"
	"	   *---------*\n"
	"		   |||\n";

ShrubberyCreationForm::ShrubberyCreationForm() 
{
}

ShrubberyCreationForm::~ShrubberyCreationForm() 
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("shrubbery creation", target, 145, 137) 
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy) 
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	(void)rhs;
	return(*this);
}

void ShrubberyCreationForm::putchar(int i, int j, int height, std::ostream &o) const
{
	if (i == height -1)
		o << '*';
	else
	{
		if (j < height - 1 + i || j == height - 1 - i)
			o << '*';
		else
		{
			if (j < height -1 + i && j > height - 1 + 1)
				o << (rand() % 2 ? '#' : ' ');
			else
				o << ' ';
		}
	}
}

void	ShrubberyCreationForm::draw_tree(std::ostream &o) const
{
	int height = rand() % 16 + 8;
	this->draw_tree(height - 1, height * 2 - 2, height, o);
		for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < height + 1; j++)
			o << (j < height - 2 ? ' ' : '|');
		o << std::endl;
	}
}

void	ShrubberyCreationForm::draw_tree(int i, int j, int height, std::ostream &o) const
{
	if (i < 0)
		return ;
	if (j <= 0)
		this->draw_tree(i - 1, height * 2 - 2, height, o);
	else
		this->draw_tree(i, j - 1, height, o);
	this->putchar(i, j, height, o);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	
	if (this->check(executor))
	{
		std::ofstream file((getTarget() + "_shrubbery").c_str());
		if (file.is_open())
		{
			file << asciiTree << std::endl;
			file.close();
		}
		else
			std::cerr << "Unable to open file" << std::endl;
	}
}