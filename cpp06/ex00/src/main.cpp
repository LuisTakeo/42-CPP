#include "./main.hpp"

void	testChar(const std::string &str)
{
	(void)str;
	std::cout << "Testando com char c";
	ScalarConverter::convert("c");
	std::cout << "Testando com char 0";
	ScalarConverter::convert("0");
	std::cout << "Testando com char 1";
	ScalarConverter::convert("1");
	std::cout << "Testando com char 2.0";
	ScalarConverter::convert("2.0");
	std::cout << "Testando com char 2.0f";
	ScalarConverter::convert("2.0f");
	std::cout << "Testando com pseudo literal";
	ScalarConverter::convert("inff");
	ScalarConverter::convert("+inff");
	ScalarConverter::convert("-inff");
	ScalarConverter::convert("nanf");
	ScalarConverter::convert("nan");

}

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