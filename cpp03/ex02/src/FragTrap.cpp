#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->_name = "RandomTrap";
	this->_attackDamage = 30;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	std::cout << "Default constructor: FragTrap has been created." << std::endl;

}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_name = name;
	this->_attackDamage = 30;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	std::cout << "Parameter constructor: FragTrap " << this->_name
		<< " has been created" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor: FragTrap has been destroyed" << std::endl;
}


FragTrap::FragTrap(FragTrap const &obj) : ClapTrap (obj)
{
	std::cout << "Copy constructor: FragTrap has been cloned" << std::endl;
	*this = obj;
}


FragTrap	&	FragTrap::operator=(FragTrap const &obj)
{
	if (this != &obj)
	{
		this->_name = obj.getName();
		this->_attackDamage = obj.getAttackDamage();
		this->_energyPoints = obj.getEnergyPoints();
		this->_hitPoints = obj.getHitPoints();
	}
	std::cout << "Assignment operator: All data has been copied to FragTrap" << std::endl;
	return *this;
}

void			FragTrap::attack(const std::string &target)
{
	if (this->_energyPoints && this->_hitPoints)
	{
		std::cout << "Frag Trap " << this->_name << " attacks " << target
			<< " causing " << this->_attackDamage << " points of damage!"
			<< std::endl;
		this->_energyPoints--;
		this->announcePoints();
	}
	else
	{
		std::cout << "Frag Trap " << this->_name
			<< (!this->_energyPoints ?
			" has no more energy )=. Bip" : " has no more hit points )=. Bop") << std::endl;
	}
}

void			FragTrap::highFiveGuys()
{
	if (this->_energyPoints && this->_hitPoints)
	{
		std::cout << this->_name << " request a high Five Guys!!!" << std::endl;
		this->_energyPoints--;
	}
	else
	{
		std::cout << "Frag Trap " << this->_name
			<< (!this->_energyPoints ?
			" has no more energy )=. Bip" : " has no more hit points )=. Bop") << std::endl;
	}
    this->announcePoints();
}