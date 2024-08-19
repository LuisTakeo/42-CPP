#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain			*_brain;
protected:
	std::string		_type;
public:
    Cat();
    Cat(std::string type);
	Cat(Cat const &obj);
    virtual ~Cat();

	Cat			&	operator=(Cat const &obj);

	virtual void	makeSound() const;
};

#endif