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
		_vector = other._vector;
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
		std::vector<int>::iterator it = std::find(this->_vector.begin(), this->_vector.end(), value);
		if (it != this->_vector.end())
			throw std::invalid_argument("Error. Duplicate value.");
		this->_vector.push_back(value);
		this->_deque.push_back(value);
	}
}

void	PMergeMe::run(char **av)
{
	putValues(av + 1);
	std::cout << COLOR_TITLE << "Before: " << COLOR_RESET << std::endl;
	printContainer(this->_deque);

	// Merging deque
	clock_t startDeque = std::clock();
	mergeInsertionSort(this->_deque);
	clock_t endDeque = std::clock();

	// Merging vector
	clock_t startVector = std::clock();
	mergeInsertionSort(this->_vector);
	clock_t endVector = std::clock();

	std::cout << COLOR_TITLE << "After: " << COLOR_RESET << std::endl;
	std::cout << COLOR_DEQUE << "deque: " << COLOR_RESET;
	printContainer(this->_deque);
	std::cout << COLOR_VECTOR << "vector: " << COLOR_RESET;
	printContainer(this->_vector);

	double timeElapsedDeque = static_cast<double>(endDeque - startDeque)
		* 1000000.0 / CLOCKS_PER_SEC;
	std::cout << "Time for deque: "
				<< std::fixed << std::setprecision(6)
				<< timeElapsedDeque << " us" << std::endl;

	double timeElapsedVector = static_cast<double>(endVector - startVector)
		* 1000000.0 / CLOCKS_PER_SEC;
	std::cout << "Time for vector: "
				<< std::fixed << std::setprecision(6)
				<< timeElapsedVector << " us" << std::endl;
}