#include "main.hpp"

int main(void)
{
	Base		*base;

	std::cout << "Test: Generate a random class" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Generating a random base class" << std::endl;
		base = Base::generate();
		std::cout << "Identifying the base class" << std::endl;
		std::cout << "Pointer: ";
		Base::identify(base);
		std::cout << "Reference: ";
		Base::identify(*base);
		delete base;
	}
	return 0;
}