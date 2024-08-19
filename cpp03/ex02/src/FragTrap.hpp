#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:

public:
    FragTrap();
    FragTrap(std::string name);
	FragTrap(FragTrap const &obj);
    ~FragTrap();

	FragTrap	&	operator=(FragTrap const &obj);

	void			attack(const std::string &target);
    void            highFiveGuys(void);
};

#endif