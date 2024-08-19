#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
protected:
	std::string		_type;
public:
    Dog();
    Dog(std::string type);
	Dog(Dog const &obj);
    virtual ~Dog();

	Dog	&	operator=(Dog const &obj);

	virtual void	makeSound() const;
};

#endif