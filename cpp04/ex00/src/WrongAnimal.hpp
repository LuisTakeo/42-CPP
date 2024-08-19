#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
	std::string		_type;
public:
    WrongAnimal();
    WrongAnimal(std::string type);
	WrongAnimal(WrongAnimal const &obj);
    virtual ~WrongAnimal();

	WrongAnimal	&	    operator=(WrongAnimal const &obj);

	std::string		getType(void) const;
    void            setType(std::string type);

	virtual void	makeSound() const;
};

#endif