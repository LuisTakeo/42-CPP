#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	this->_size = 0;
	this->_array = NULL;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->_size = n;
	this->_array = new T[n];
}

template <typename T>
Array<T>::Array(Array const &other)
{
	this->_size = other._size;
	this->_array = new T[_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = other._array[i];
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->_array;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other)
{
	if (this != &other)
	{
		delete[] _array;
		this->_size = other._size;
		this->_array = new T[this->_size];
		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = other._array[i];
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size)
		throw std::out_of_range("Index out of range");
	return this->_array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return this->_size;
}