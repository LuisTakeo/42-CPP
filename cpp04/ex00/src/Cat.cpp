#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->setType("Cat");
}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "Cat parameter constructor called" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(Cat const &obj) : Animal(obj)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = obj;
}

Cat	&   Cat::operator=(Cat const &obj)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &obj) {
		this->setType(obj.getType());
	}
	return (*this);
}

void	Cat::makeSound(void) const { std::cout << "Meaw meaw" << std::endl; }