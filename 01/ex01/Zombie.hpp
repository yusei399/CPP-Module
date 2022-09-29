#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
private:
	std::string _name;
public:
	void	announce(void)	const;
	void	push_name(const std::string &name);
	Zombie(const std::string &_name);
	Zombie(void);
	~Zombie(void);
};

#endif