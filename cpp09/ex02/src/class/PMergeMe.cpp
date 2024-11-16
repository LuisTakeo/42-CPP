#include "PMergeMe.hpp"

PMergeMe::PMergeMe()
{
}

PMergeMe::PMergeMe(PMergeMe const &other)
{
	*this = other;
}

PMergeMe::~PMergeMe()
{
}

PMergeMe &PMergeMe::operator=(PMergeMe const &other)
{
	if (this != &other)
	{
		_list = other._list;
		_deque = other._deque;
	}
	return *this;
}

bool	PMergeMe::isNumber(char *str)
{
	for (size_t i = 0; str[i]; i++)
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			continue;
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

void	PMergeMe::putValues(char **av)
{
	long	value;

	for (int i = 0; av[i]; i++)
	{
		// if (not isNumber(av[i]))
		// 	throw std::invalid_argument("Error.: '" + (std::string)(av[i]) + "' is not a number.");

		size_t	result;
		char	c;

		result = std::sscanf(av[i], "%ld%c", &value, &c);
		if (result != 1)
			throw std::invalid_argument("Error.: '" + (std::string)(av[i]) + "' is not a number.");
		if (value < 0)
			throw std::invalid_argument("Error. Negative number.");
		if (value > INT_MAX)
			throw std::invalid_argument("Error. Number too big.");
		_list.push_back(value);
		_deque.push_back(value);
	}
}

void	PMergeMe::run(char **av)
{
	putValues(av + 1);
}