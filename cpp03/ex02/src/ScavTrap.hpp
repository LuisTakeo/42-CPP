#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:

public:
    ScavTrap();
    ScavTrap(std::string name);
	ScavTrap(ScavTrap const &obj);
    ~ScavTrap();

	ScavTrap	&	operator=(ScavTrap const &obj);

	void			attack(const std::string &target);
    void            guardGate(void);
};

#endif