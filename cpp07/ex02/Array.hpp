#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <cstdlib>
# include <exception>


template <typename T>
class Array
{
	private:
		unsigned int	_size;
		T				*_array;

	public:
		Array();
		Array(unsigned int n);
		Array(Array const &other);
		~Array();
		Array &operator=(Array const &other);
		T &operator[](unsigned int index);
		unsigned int size() const;
};

#include "Array.tpp"

#endif