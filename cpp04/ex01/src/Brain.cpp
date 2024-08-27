#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->_ideas[i] = "thinking";
	}
}

Brain::Brain(std::string idea)
{
	std::cout << "Brain parameter constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->_ideas[i] = idea;
	}
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(Brain const &obj)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = obj;
}

Brain	&   Brain::operator=(Brain const &obj)
{
	std::cout << "Brain assignment operator call" << std::endl;
	if (this != &obj)
	{
		for (int i = 0; i < 100; i++)
		{
			this->_ideas[i] = obj._ideas[i];
		}
	}
	return (*this);
}

std::string Brain::getIdea(int i) const
{
	if (i < 0 || i >= 100)
	{
		std::cout << "out of range" << std::endl;
		return ("");
	}
	return (this->_ideas[i]);
}

void        Brain::setIdea(int i, std::string idea)
{
	if (i < 0 || i >= 100)
	{
		std::cout << "out of range" << std::endl;
		return ;
	}
	this->_ideas[i] = idea;
}
