#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
protected:

public:
    WrongCat();
    WrongCat(std::string type);
	WrongCat(WrongCat const &obj);
    virtual ~WrongCat();

	WrongCat			&	operator=(WrongCat const &obj);

	void	makeSound() const;
};

#endif