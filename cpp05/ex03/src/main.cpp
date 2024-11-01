#include "./main.hpp"

void	printError(std::string const &msg)
{
	std::cerr << ERROR_COLOR << "Error: " << msg << RESET_COLOR << std::endl;

}

void	printTitle(std::string const &msg)
{
	std::cout << TITLE_COLOR << msg << RESET_COLOR << std::endl;
	std::cout << "--------------------------------" << std::endl;
}

void	testInternValid()
{
	try
	{

		Intern		intern;
		Bureaucrat	bureaucrat("bureaucrat", 1);
		AForm		*form;

		printTitle("Test Intern Valid");
		form = intern.makeForm("presidential pardon", "target");
		bureaucrat.signForm(*form);
		std::cout << *form;
		bureaucrat.executeForm(*form);
		delete form;
		form = intern.makeForm("robotomy request", "target");
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		delete form;
		form = intern.makeForm("shrubbery creation", "target");
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		delete form;

	}
	catch (std::exception &e)
	{
		printError(e.what());
	}

}

void	testInternInvalid()
{
	printTitle("Test Intern Invalid");
	try
	{
		Intern		intern;
		Bureaucrat	bureaucrat("bureaucrat", 1);
		AForm		*form;

		form = intern.makeForm("presidential bardon", "target");
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		delete form;
		form = intern.makeForm("robotomy request", "target");
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		delete form;
		form = intern.makeForm("shrubbery creation", "target");
		bureaucrat.signForm(*form);
		bureaucrat.executeForm(*form);
		delete form;
	}
	catch (std::exception &e)
	{
		printError(e.what());
	}
}

int	main()
{
	testInternValid();
	testInternInvalid();
	return (0);
}