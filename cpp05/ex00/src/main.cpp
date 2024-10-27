#include "./main.hpp"

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
		std::cout << burocrat << std::endl;
		std::cout << SUCCESS_COLOR << "Success!!!" << RESET_COLOR << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
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
		std::cout << burocrat << std::endl;
		std::cout << SUCCESS_COLOR << "Success!!!" << RESET_COLOR << std::endl;
	}
	catch (std:: exception &e)
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
		std::cout << burocrat << std::endl;
		std::cout << SUCCESS_COLOR << "Success!!!" << RESET_COLOR << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		print_error(e.what());
	}
}

void	test_if_grade_is_one_thousand()
{
	std::cout << TITLE_COLOR << "Test if grade is too low" << RESET_COLOR << std::endl;
	try
	{
		std::cout << "Creating a burocrat with grade 151" << std::endl;
		Bureaucrat	burocrat("burocrat", 151);
		std::cout << burocrat << std::endl;
		std::cout << SUCCESS_COLOR << "Success!!!" << RESET_COLOR << std::endl;
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
		std::cout << burocrat << std::endl;

		std::cout << "----------------" << std::endl;

		std::cout << "Creating a burocrat with grade 150" << std::endl;
		Bureaucrat	burocrat2("burocrat 2", 150);
		std::cout << burocrat2 << std::endl;

		std::cout << "----------------" << std::endl;

		std::cout << "Decrementing " << burocrat.getName() << "'s grade" << std::endl;
		burocrat.decrementGrade();
		std::cout << burocrat << std::endl;

		std::cout << "----------------" << std::endl;

		std::cout << "Incrementing " << burocrat2.getName() << "'s grade" << std::endl;
		burocrat2.incrementGrade();
		std::cout << burocrat2 << std::endl;

		std::cout << "----------------" << std::endl;

		std::cout << "Creating a copy of " << burocrat.getName() << std::endl;
		Bureaucrat	burocrat3(burocrat);
		std::cout << burocrat3 << std::endl;

		std::cout << "----------------" << std::endl;

		std::cout << "Assignment of " << burocrat2.getName() << " to " << burocrat.getName() << std::endl;
		burocrat = burocrat2;
		std::cout << burocrat << std::endl;
		std::cout << burocrat2 << std::endl;

		std::cout << "----------------" << std::endl;

		std::cout << SUCCESS_COLOR << "Success!!!" << RESET_COLOR << std::endl;
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
		std::cout << burocrat << std::endl;

		std::cout << "Incrementing grade" << std::endl;
		burocrat.incrementGrade();
		std::cout << burocrat << std::endl;
		burocrat.incrementGrade();
		std::cout << burocrat << std::endl;
		std::cout << SUCCESS_COLOR << "Success!!!" << RESET_COLOR << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		print_error(e.what());
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		print_error(e.what());
	}
	catch (std::exception &e)
	{
		print_error(e.what());
	}
}

void	test_decrement_grade_invalid()
{
	std::cout << TITLE_COLOR << "Test decrement grade invalid" << RESET_COLOR << std::endl;
	try
	{
		std::cout << "Creating a burocrat with grade 150" << std::endl;
		Bureaucrat	burocrat("burocrat", 150);
		std::cout << burocrat << std::endl;
		std::cout << "Decrementing grade" << std::endl;
		burocrat.decrementGrade();
		std::cout << burocrat << std::endl;
		std::cout << "Decrementing grade" << std::endl;
		burocrat.decrementGrade();
		std::cout << burocrat << std::endl;
		std::cout << SUCCESS_COLOR << "Success!!!" << RESET_COLOR << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		print_error(e.what());
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		print_error(e.what());
	}
	catch (std::exception &e)
	{
		print_error(e.what());
	}
}

void	test_bureaucrats()
{
	std::cout << TITLE_COLOR << "Testing Bureaucrats" << RESET_COLOR << std::endl;
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
	test_decrement_grade_invalid();
	std::cout << "================" << std::endl;
}

int	main()
{
	test_bureaucrats();
	return (0);
}