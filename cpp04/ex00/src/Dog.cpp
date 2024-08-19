#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "Dog defaut constructor called" << std::endl;
	this->setType("Dog");
}

Dog::Dog(std::string type) : Animal(type)
{
	std::cout << "Dog parameter constructor called" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(Dog const &obj) : Animal(obj)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = obj;
}

Dog	&Dog::operator=(Dog const &obj)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &obj) {
		this->setType(obj.getType());
	}
	return (*this);
}

void	Dog::makeSound(void) const { std::cout << "Au Au... Arf Arf AU AU" << std::endl; }