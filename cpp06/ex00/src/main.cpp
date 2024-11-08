#include "./main.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Invalid number of arguments" << std::endl;
		return EXIT_FAILURE;
	}
	std::string str = argv[1];
	ScalarConverter::convert(str);
	return EXIT_SUCCESS;
}