#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class	ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
		void	execute(const Bureaucrat &executor) const;
	private:
		void	draw_tree(std::ostream &o) const;
		void	draw_tree(int i, int j, int height, std::ostream &o) const;
		void	putchar(int i, int j, int height, std::ostream &o) const;
		ShrubberyCreationForm();
		static const char * asciiTree;
};

#endif
