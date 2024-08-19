#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->_name = "RandomTrap";
	this->_attackDamage = 0;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	std::cout << "Default constructor: ClapTrap has been created." << std::endl;

}

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_attackDamage = 0;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	std::cout << "Parameter constructor: ClapTrap " << this->_name
		<< " has been created" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor: ClapTrap has been destroyed" << std::endl;
}


ClapTrap::ClapTrap(ClapTrap const &obj)
{
	std::cout << "Copy constructor: ClapTrap has been cloned" << std::endl;
	*this = obj;
}


ClapTrap	&	ClapTrap::operator=(ClapTrap const &obj)
{
	if (this != &obj)
	{
		this->_name = obj.getName();
		this->_attackDamage = obj.getAttackDamage();
		this->_energyPoints = obj.getEnergyPoints();
		this->_hitPoints = obj.getHitPoints();
	}
	std::cout << "Assignment operator: All data has been copied to ClapTrap" << std::endl;
	return *this;
}

void			ClapTrap::announcePoints()
{
	std::cout << "Your hit points: " << this->getHitPoints()
		<< ". Your energy points: " << this->getEnergyPoints() << std::endl;
}

void			ClapTrap::announceDetails()
{
	std::cout << "Name: " << this->_name << std::endl
		<< "Hit points: " << this->_hitPoints << std::endl
		<< "Energy Points: " << this->_energyPoints << std::endl
		<< "Attack Damage: " << this->_attackDamage << std::endl;
}

std::string		ClapTrap::getName(void) const { return (this->_name); }
unsigned int	ClapTrap::getHitPoints(void) const { return (this->_hitPoints); }
unsigned int	ClapTrap::getEnergyPoints(void) const { return (this->_energyPoints); }
unsigned int	ClapTrap::getAttackDamage(void) const { return (this->_attackDamage); }


void			ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints && this->_hitPoints)
	{
		std::cout << "Clap Trap " << this->_name << " attacks " << target
			<< " causing " << this->_attackDamage << " points of damage!"
			<< std::endl;
		this->_energyPoints--;
		this->announcePoints();
	}
	else
	{
		std::cout << "Clap Trap " << this->_name
			<< (!this->_energyPoints ?
			" has no more energy )=. Bip" : " has no more hit points )=. Bop") << std::endl;
	}
}

void			ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->_hitPoints)
	{
		std::cout << this->_name << " is already dead. blorp" << std::endl;
		return ;
	}
	amount > this->_hitPoints ?
		this->_hitPoints -= this->_hitPoints
		: this->_hitPoints -= amount;
	std::cout << this->_name << " has taken "
		<< amount << " points of damage." << std::endl;
	this->announcePoints();
}

void			ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints)
	{
		std::cout << this->_name
			<< " has been repaired your hit points!" << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
		this->announcePoints();
	}
	else
	{
		std::cout << this->_name
			<< " has no more energy )=. Bip" << std::endl;
	}
}