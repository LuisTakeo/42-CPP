#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	std::string		_type;
public:
    Animal();
    Animal(std::string type);
	Animal(Animal const &obj);
    virtual ~Animal();

	Animal	&	    operator=(Animal const &obj);

	std::string		getType(void) const;
    void            setType(std::string type);

	virtual void	makeSound() const;
};

#endif