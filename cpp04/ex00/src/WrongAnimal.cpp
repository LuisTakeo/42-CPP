#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
	setType("WrongAnimal");
}

WrongAnimal::WrongAnimal(std::string type)
{
	std::cout << "WrongAnimal parameter constructor called" << std::endl;
	setType(type);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &obj)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = obj;
}

WrongAnimal	&   WrongAnimal::operator=(WrongAnimal const &obj)
{
	std::cout << "WrongAnimal assignment operator call" << std::endl;
	if (this != &obj) {
		setType(obj.getType());
	}
	return (*this);
}

std::string WrongAnimal::getType() const { return (this->_type); }

void        WrongAnimal::setType(std::string type) { this->_type = type; }

void	WrongAnimal::makeSound(void) const
{
    	std::cout << "Generic wrong animal sound......." << std::endl;
}