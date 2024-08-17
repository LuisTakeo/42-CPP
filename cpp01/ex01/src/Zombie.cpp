#include "Zombie.hpp"

Zombie::Zombie()
{
	this->_name = "";
}

Zombie::Zombie(std::string name)
{
	this->setName(name);
}

Zombie::~Zombie()
{
	std::cout << this->_name << " has been destroyed." << std::endl;
}

std::string Zombie::getName(void)
{
	return (this->_name);
}

void        Zombie::setName(std::string &name)
{
	this->_name = name;
}

void        Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}