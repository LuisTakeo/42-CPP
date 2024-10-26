#include "./class/Bureaucrat.hpp"

void	print_error(std::string const &msg)
{
	std::cerr << ERROR_COLOR << "Error: " << msg << RESET_COLOR << std::endl;
}

void	test_if_grade_is_too_high()
{
	std::cout << TITLE_COLOR << "Test if grade is too high" << RESET_COLOR << std::endl;
	try
	{
		std::cout << "Creating a burocrat with grade 0" << std::endl;
		Bureaucrat	burocrat("burocrat", 0);
		std::cout << "Name: " << burocrat.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		print_error(e.what());
	}
}

void	test_if_grade_is_negative()
{
	std::cout << TITLE_COLOR << "Test if grade is negative" << RESET_COLOR << std::endl;
	try
	{
		std::cout << "Creating a burocrat with grade -1" << std::endl;
		Bureaucrat	burocrat("burocrat", -1);
		std::cout << "Name: " << burocrat.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		print_error(e.what());
	}
}

void	test_if_grade_is_too_low()
{
	std::cout << TITLE_COLOR << "Test if grade is too low" << RESET_COLOR << std::endl;
	try
	{
		std::cout << "Creating a burocrat with grade 151" << std::endl;
		Bureaucrat	burocrat("burocrat", 151);
		std::cout << "Name: " << burocrat.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		print_error(e.what());
	}
}

void	test_grade_valid()
{
	std::cout << TITLE_COLOR << "Test grade valid" << RESET_COLOR << std::endl;
	try
	{
		std::cout << "Creating a burocrat with grade 1" << std::endl;
		Bureaucrat	burocrat("burocrat", 1);
		std::cout << "Name: " << burocrat.getName() << std::endl;
		std::cout << "Grade: " << burocrat.getGrade() << std::endl;

		std::cout << "Creating a burocrat with grade 150" << std::endl;
		Bureaucrat	burocrat2("burocrat 2", 150);
		std::cout << "Name: " << burocrat2.getName() << std::endl;
		std::cout << "Grade: " << burocrat2.getGrade() << std::endl;
	}
	catch (std::exception &e)
	{
		print_error(e.what());
	}
}

void	test_increment_grade_invalid()
{
	std::cout << TITLE_COLOR << "Test increment grade invalid" << RESET_COLOR << std::endl;
	try
	{
		std::cout << "Creating a burocrat with grade 1" << std::endl;
		Bureaucrat	burocrat("burocrat", 1);
		std::cout << "Name: " << burocrat.getName() << std::endl;
		std::cout << "Grade: " << burocrat.getGrade() << std::endl;
		std::cout << "Incrementing grade" << std::endl;
		burocrat.incrementGrade();
		std::cout << "Grade: " << burocrat.getGrade() << std::endl;
		std::cout << "Incrementing grade" << std::endl;
		burocrat.incrementGrade();
		std::cout << "Grade: " << burocrat.getGrade() << std::endl;
	}
	catch (std::exception &e)
	{
		print_error(e.what());
	}
}

int	main()
{
	test_if_grade_is_too_high();
	std::cout << "================" << std::endl;
	test_if_grade_is_negative();
	std::cout << "================" << std::endl;
	test_if_grade_is_too_low();
	std::cout << "================" << std::endl;
	test_grade_valid();
	std::cout << "================" << std::endl;
	test_increment_grade_invalid();
	std::cout << "================" << std::endl;
	return (0);
}