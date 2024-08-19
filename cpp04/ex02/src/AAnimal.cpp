#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
	std::cout << "AAnimal default constructor called" << std::endl;
	setType("AAnimal");
}

AAnimal::AAnimal(std::string type)
{
	std::cout << "AAnimal parameter constructor called" << std::endl;
	setType(type);
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const &obj)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = obj;
}

AAnimal	&   AAnimal::operator=(AAnimal const &obj)
{
	std::cout << "AAnimal assignment operator call" << std::endl;
	if (this != &obj) {
		setType(obj.getType());
	}
	return (*this);
}

std::string AAnimal::getType() const { return (this->_type); }

void        AAnimal::setType(std::string type) { this->_type = type; }
