#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class AAnimal
{
protected:
	std::string		_type;
public:
    AAnimal();
    AAnimal(std::string type);
	AAnimal(AAnimal const &obj);
    virtual ~AAnimal();

	AAnimal	&	    operator=(AAnimal const &obj);

	std::string		getType(void) const;
    void            setType(std::string type);

	// Pure virtual function
	virtual void	makeSound() const = 0;
};

#endif