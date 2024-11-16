#include "main.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc < 2)
			throw std::invalid_argument("Error. Invalid number of arguments. Usage: ./PMergeMe value1 value2 ...");

		PMergeMe pMergeMe;
		pMergeMe.run(argv);

	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}