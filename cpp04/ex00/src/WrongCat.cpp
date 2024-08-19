#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	this->setType("WrongCat");
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
	std::cout << "WrongCat parameter constructor called" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &obj) : WrongAnimal(obj)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = obj;
}

WrongCat	&   WrongCat::operator=(WrongCat const &obj)
{
	std::cout << "WrongCat assignment operator called" << std::endl;
	if (this != &obj) {
		this->setType(obj.getType());
	}
	return (*this);
}

void	WrongCat::makeSound(void) const { std::cout << "Meaw meaw" << std::endl; }