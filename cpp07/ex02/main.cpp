#include <iostream>
#include "Array.hpp"

#define MAX_VAL 15
#define COLOR "\033[0;32m"
#define RESET "\033[0m"

void	testArrayInt()
{
	Array<int> array(MAX_VAL);

	std::cout << COLOR << "Array<int> test" << RESET << std::endl;
	std::cout << "Array size: " << array.size() << std::endl;
	std::cout << "Array content: " << std::endl;
	for (unsigned i = 0; i < array.size(); i++)
	{
		array[i] = i;
		std::cout << "Array [" << i << "]: " << array[i] << " ";
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
	for (unsigned i = 0; i < array.size(); i++)
	{
		array[i] = std::string("AI AI ");
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
	testArrayInt();
	testArrayString();
    return 0;
}