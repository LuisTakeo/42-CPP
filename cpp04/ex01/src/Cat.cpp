#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->setType("Cat");
	this->_brain = new Brain("Meaw");
}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "Cat parameter constructor called" << std::endl;
	this->_brain = new Brain("Meaw");
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

Cat::Cat(Cat const &obj) : Animal(obj)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->setType(obj.getType());
	this->_brain = new Brain(*obj._brain);

}

Cat	&   Cat::operator=(Cat const &obj)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &obj) {
		this->setType(obj.getType());
		delete this->_brain;
		this->_brain = new Brain(*obj._brain);
	}
	return (*this);
}

void	Cat::makeSound(void) const { std::cout << (this->_brain ? this->_brain->getIdea(0) : "Meow") << std::endl; }