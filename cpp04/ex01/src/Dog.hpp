#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain			*_brain;
protected:

public:
    Dog();
    Dog(std::string type);
	Dog(Dog const &obj);
    virtual ~Dog();

	Dog	&	operator=(Dog const &obj);

	virtual void	makeSound() const;
};

#endif