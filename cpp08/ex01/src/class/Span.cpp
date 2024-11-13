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

template <typename TIterator>
void Span::fillVector(TIterator begin, TIterator end)
{
	if (this->_nums.size() + std::distance(begin, end) > this->_size)
		throw std::length_error("Span is full");

	this->_nums.insert(this->_nums.end(), begin, end);
}

