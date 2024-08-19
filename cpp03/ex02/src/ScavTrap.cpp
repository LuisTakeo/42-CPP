#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_name = "RandomTrap";
	this->_attackDamage = 20;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	std::cout << "Default constructor: ScavTrap has been created." << std::endl;

}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_name = name;
	this->_attackDamage = 20;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	std::cout << "Parameter constructor: ScavTrap " << this->_name
		<< " has been created" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor: ScavTrap has been destroyed" << std::endl;
}


ScavTrap::ScavTrap(ScavTrap const &obj) : ClapTrap (obj)
{
	std::cout << "Copy constructor: ScavTrap has been cloned" << std::endl;
	*this = obj;
}


ScavTrap	&	ScavTrap::operator=(ScavTrap const &obj)
{
	if (this != &obj)
	{
		this->_name = obj.getName();
		this->_attackDamage = obj.getAttackDamage();
		this->_energyPoints = obj.getEnergyPoints();
		this->_hitPoints = obj.getHitPoints();
	}
	std::cout << "Assignment operator: All data has been copied to ScavTrap" << std::endl;
	return *this;
}

void			ScavTrap::attack(const std::string &target)
{
	if (this->_energyPoints && this->_hitPoints)
	{
		std::cout << "Scav Trap " << this->_name << " attacks " << target
			<< " causing " << this->_attackDamage << " points of damage!"
			<< std::endl;
		this->_energyPoints--;
		this->announcePoints();
	}
	else
	{
		std::cout << "Scav Trap " << this->_name
			<< (!this->_energyPoints ?
			" has no more energy )=. Bip" : " has no more hit points )=. Bop") << std::endl;
	}
}

void			ScavTrap::guardGate()
{
	if (this->_energyPoints && this->_hitPoints)
	{
		std::cout << "Scav Trap " << this->_name << " enter in GuardGate Mode " << std::endl;
		this->_energyPoints--;
	}
	else
	{
		std::cout << "Scav Trap " << this->_name
			<< (!this->_energyPoints ?
			" has no more energy )=. Bip" : " has no more hit points )=. Bop") << std::endl;
	}
    this->announcePoints();
}