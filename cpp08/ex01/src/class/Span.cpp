#include "Span.hpp"

Span::Span()
{
	this->_size = 0;
	this->_nums = std::vector<int>();
}

Span::Span(unsigned int n)
{
	this->_size = n;
	this->_nums = std::vector<int>();
}

Span::Span(const Span &src)
{
	*this = src;
}

Span::~Span()
{
}

Span &Span::operator=(const Span &src)
{
	if (this != &src)
	{
		this->_size = src._size;
		this->_nums = src._nums;
	}
	return *this;
}

int &Span::operator[](unsigned int index)
{
	if (index >= this->_nums.size())
		throw std::out_of_range("Index out of range");
	return this->_nums[index];
}

const int &Span::operator[](unsigned int index) const
{
	if (index >= this->_nums.size())
		throw std::out_of_range("Index out of range");
	return this->_nums[index];
}

void Span::addNumber(int n)
{
	if (this->_nums.size() >= this->_size)
		throw std::length_error("Span is full");
	this->_nums.push_back(n);
}

int Span::shortestSpan()
{
	if (this->_nums.size() <= 1)
		throw std::length_error("Span is too short");

	std::vector<int> temp = this->_nums;

	std::sort(temp.begin(), temp.end());
	int shortest = temp[1] - temp[0];

	for (unsigned int i = 2; i < temp.size(); i++)
	{
		int diff = temp[i] - temp[i - 1];
		if (diff < shortest)
			shortest = diff;
	}
	return shortest;
}

int Span::longestSpan()
{
	if (this->_nums.size() <= 1)
		throw std::length_error("Span is too short");

	std::vector<int> temp = this->_nums;

	std::sort(temp.begin(), temp.end());
	return temp[temp.size() - 1] - temp[0];
}

unsigned int Span::getSize() const
{
	return this->_size;
}

std::vector<int> Span::getVector() const
{
	return this->_nums;
}

// inline void printValue(int n) {	std::cout << n << " ";}

void Span::printValues() const
{
	if (!this->_nums.size())
		std::cout << "No values to print";
	std::for_each(this->_nums.begin(), this->_nums.end(), PrintValue());
	std::cout << std::endl;
}
