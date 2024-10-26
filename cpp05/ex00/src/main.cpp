#include "./class/Bureaucrat.hpp"

void	test_if_grade_is_too_high()
{
	try
	{
		Bureaucrat	burocrat("burocrat", 0);
		std::cout << burocrat.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	main()
{
	test_if_grade_is_too_high();

	return (0);
}