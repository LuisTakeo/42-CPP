#include "./main.hpp"


int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw std::invalid_argument("Error: invalid number of arguments");

		BitcoinExchange exchange;
		exchange.printFile(argv[1]);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}