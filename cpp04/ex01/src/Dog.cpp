#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "Dog defaut constructor called" << std::endl;
	this->setType("Dog");
	this->_brain = new Brain("Au Au");
}

Dog::Dog(std::string type) : Animal(type)
{
	std::cout << "Dog parameter constructor called" << std::endl;
	this->_brain = new Brain("Au Au");
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

Dog::Dog(Dog const &obj) : Animal(obj)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->setType(obj.getType());
	this->_brain = new Brain(*obj._brain);
}

Dog	&Dog::operator=(Dog const &obj)
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &obj) {
		this->setType(obj.getType());
		delete this->_brain;
		this->_brain = new Brain(*obj._brain);
	}
	return (*this);
}

void	Dog::makeSound(void) const { std::cout << this->_brain->getIdea(0) << std::endl; }