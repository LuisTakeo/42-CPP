#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
protected:

public:
    Cat();
    Cat(std::string type);
	Cat(Cat const &obj);
    virtual ~Cat();

	Cat			&	operator=(Cat const &obj);

	virtual void	makeSound() const;
};

#endif