#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
private:
	std::string		_ideas[100];
public:
    Brain();
	Brain(std::string idea);
	Brain(Brain const &obj);
    virtual ~Brain();

	Brain	&	    operator=(Brain const &obj);

	std::string		getIdea(int i) const;
    void            setIdea(int i, std::string idea);
};

#endif