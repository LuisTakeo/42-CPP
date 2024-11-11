#include <iostream>
#include <sstream>
#include "Array.hpp"

#define MAX_VAL 15
#define COLOR "\033[0;32m"
#define RESET "\033[0m"

void	testInitEmptyArray()
{
	Array<int> array;
	Array<int> array2(13);
	Array<int> array3(array2);
	Array<int> array4 = array3;

	std::cout << COLOR << "Array<int> test" << RESET << std::endl;
	std::cout << "Array size: " << array.size() << std::endl;
	std::cout << "Array content: " << std::endl;
	for (unsigned i = 0; i < array.size(); i++)
	{
		// array[i] = i;
		std::cout << "Array [" << i << "]: " << array[i] << std::endl;
	}
	std::cout << std::endl;


	std::cout << "Array2 size: " << array2.size() << std::endl;
	std::cout << "Array2 content: " << std::endl;
	for (unsigned i = 0; i < array2.size(); i++)
	{
		// array2[i] = i;
		std::cout << "Array2 [" << i << "]: " << array2[i] << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Array3 size: " << array
	.size() << std::endl;
	std::cout << "Array3 content: " << std::endl;
	for (unsigned i = 0; i < array3.size(); i++)
	{
		// array3[i] = i;
		std::cout << "Array3 [" << i << "]: " << array3[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Array4 size: " << array4.size() << std::endl;

	std::cout << "Array4 content: " << std::endl;
	for (unsigned i = 0; i < array4.size(); i++)
	{
		array4[i] = i;
		std::cout << "Array4 [" << i << "]: " << array4[i] << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Test out of range" << std::endl;

	try
	{
		array[MAX_VAL] = 0;
		std::cout << "Array[MAX_VAL]" << array[MAX_VAL] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Array<int> test passed" << std::endl;
}


void	testArrayInt()
{
	Array<int> array(MAX_VAL);

	std::cout << COLOR << "Array<int> test" << RESET << std::endl;
	std::cout << "Array size: " << array.size() << std::endl;
	std::cout << "Array content: " << std::endl;
	for (unsigned i = 0; i < array.size(); i++)
	{
		array[i] = i;
		std::cout << "Array [" << i << "]: " << array[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Test out of range" << std::endl;
	try
	{
		array[MAX_VAL] = 0;
		std::cout << "Array[MAX_VAL]" << array[MAX_VAL] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Array<int> test passed" << std::endl;
}


void	testArrayString()
{
	Array<std::string> array(MAX_VAL);

	std::cout << COLOR << "Array<std::string> test" << RESET << std::endl;
	std::cout << "Array size: " << array.size() << std::endl;
	std::cout << "Array content: " << std::endl;
	std::stringstream ss;
	for (unsigned i = 0; i < array.size(); i++)
	{
		ss << i;
		array[i] = ss.str();
		ss.str("");
		if (i && !(i % 3))
			array[i] = std::string("fizz");
		if (i && !(i % 5))
			array[i] = std::string("buzz");
		if (i && !(i % 3) && !(i % 5))
			array[i] = std::string("fizzbuzz");
		std::cout << "Array [" << i << "]: " << array[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Test out of range" << std::endl;
	try
	{
		array[MAX_VAL] = "0";
		std::cout << "Array[MAX_VAL]" << array[MAX_VAL] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Array<std::string> test passed" << std::endl;
}

int main(int, char**)
{
	testInitEmptyArray();
	testArrayInt();
	testArrayString();
    return 0;
}