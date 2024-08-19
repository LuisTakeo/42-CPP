#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal default constructor called" << std::endl;
	setType("Animal");
}

Animal::Animal(std::string type)
{
	std::cout << "Animal parameter constructor called" << std::endl;
	setType(type);
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(Animal const &obj)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = obj;
}

Animal	&   Animal::operator=(Animal const &obj)
{
	std::cout << "Animal assignment operator call" << std::endl;
	if (this != &obj) {
		setType(obj.getType());
	}
	return (*this);
}

std::string Animal::getType() const { return (this->_type); }

void        Animal::setType(std::string type) { this->_type = type; }

void	Animal::makeSound(void) const
{
    	std::cout << "Generic animal sound......." << std::endl;
}