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

void	testShrubberyCreationFormValid()
{
	printTitle("Test ShrubberyCreationForm Valid");
	try
	{
		Bureaucrat	bureaucrat("Alfredo", 126);
		ShrubberyCreationForm	shrubberyCreationForm("farm");

		bureaucrat.signForm(shrubberyCreationForm);
		bureaucrat.executeForm(shrubberyCreationForm);
	}
	catch (std::exception &e)
	{
		printError(e.what());
	}
}

void	testShrubberyCreationBureaucratFormInvalid()
{
	printTitle("Test ShrubberyCreationForm Bureaucrat Form Invalid");
	try
	{
		std::cout << "Creating bureaucrat with grade 146 and trying to sign/execute form" << std::endl;
		Bureaucrat	bureaucrat("Noah", 146);
		ShrubberyCreationForm	shrubberyCreationForm("farm");

		bureaucrat.signForm(shrubberyCreationForm);
		bureaucrat.executeForm(shrubberyCreationForm);

		std::cout << "Creating bureaucrat with grade 145 and trying to sign/execute form" << std::endl;
		std::cout << "The form will be signed but the bureaucrat will not be able to execute it" << std::endl;

		Bureaucrat	bureaucrat2("Noah", 145);

		bureaucrat2.signForm(shrubberyCreationForm);
		bureaucrat2.executeForm(shrubberyCreationForm);

		std::cout << "Creating bureaucrat with grade 137 and trying to sign/execute previous form" << std::endl;
		std::cout << "The form will be occur an error on sign but the bureaucrat will able to execute it" << std::endl;

		Bureaucrat	bureaucrat3("AnteDEGUEMON", 137);

		bureaucrat3.signForm(shrubberyCreationForm);
		bureaucrat3.executeForm(shrubberyCreationForm);
		}
	catch (std::exception &e)
	{
		printError(e.what());
	}

	try
	{
		/* code */
	}
	catch(const std::exception& e)
	{
		printError(e.what());
	}

}

void	testShrubbery()
{
	testShrubberyCreationFormValid();
	testShrubberyCreationBureaucratFormInvalid();
}

void	testRobotomyValid()
{
	printTitle("Test RobotomyRequestForm Valid");
	try
	{
		Bureaucrat	bureaucrat("Alfredo", 45);
		RobotomyRequestForm	robotomyRequestForm("farm");

		bureaucrat.signForm(robotomyRequestForm);
		bureaucrat.executeForm(robotomyRequestForm);
		bureaucrat.executeForm(robotomyRequestForm);
		bureaucrat.executeForm(robotomyRequestForm);
		bureaucrat.executeForm(robotomyRequestForm);
		bureaucrat.executeForm(robotomyRequestForm);
		bureaucrat.executeForm(robotomyRequestForm);
	}
	catch (std::exception &e)
	{
		printError(e.what());
	}
}

void	testRobotomyInvalid()
{
	printTitle("Test RobotomyRequestForm Invalid");
	try
	{
		std::cout << "Creating bureaucrat with grade 73 and trying to sign/execute form" << std::endl;
		Bureaucrat	bureaucrat("Noah", 73);
		RobotomyRequestForm	robotomyRequestForm("farm");

		bureaucrat.signForm(robotomyRequestForm);
		bureaucrat.executeForm(robotomyRequestForm);

		std::cout << "Creating bureaucrat with grade 72 and trying to sign/execute form" << std::endl;
		std::cout << "The form will be signed but the bureaucrat will not be able to execute it" << std::endl;

		Bureaucrat	bureaucrat2("Noah", 72);

		bureaucrat2.signForm(robotomyRequestForm);
		bureaucrat2.executeForm(robotomyRequestForm);

		std::cout << "Creating bureaucrat with grade 45 and trying to sign/execute previous form" << std::endl;
		std::cout << "The form will be occur an error on sign but the bureaucrat will able to execute it" << std::endl;

		Bureaucrat	bureaucrat3("AnteDEGUEMON", 45);

		bureaucrat3.signForm(robotomyRequestForm);
		bureaucrat3.executeForm(robotomyRequestForm);
		}
	catch (std::exception &e)
	{
		printError(e.what());
	}
}

void	testRobotomy()
{
	testRobotomyValid();
	testRobotomyInvalid();
}

void	testPresidentialValid()
{
	printTitle("Test PresidentialPardonForm Valid");
	try
	{
		Bureaucrat	bureaucrat("Alfredo", 5);
		PresidentialPardonForm	presidentialPardonForm("farm");

		bureaucrat.signForm(presidentialPardonForm);
		bureaucrat.executeForm(presidentialPardonForm);
	}
	catch (std::exception &e)
	{
		printError(e.what());
	}
}

void	testPresidentialInvalid()
{
	printTitle("Test PresidentialPardonForm Invalid");
	try
	{
		std::cout << "Creating bureaucrat with grade 26 and trying to sign/execute form" << std::endl;
		Bureaucrat	bureaucrat("Noah", 26);
		PresidentialPardonForm	presidentialPardonForm("farm");

		bureaucrat.signForm(presidentialPardonForm);
		bureaucrat.executeForm(presidentialPardonForm);

		std::cout << "Creating bureaucrat with grade 25 and trying to sign/execute form" << std::endl;
		std::cout << "The form will be signed but the bureaucrat will not be able to execute it" << std::endl;

		Bureaucrat	bureaucrat2("Noah", 25);

		bureaucrat2.signForm(presidentialPardonForm);
		bureaucrat2.executeForm(presidentialPardonForm);

		std::cout << "Creating bureaucrat with grade 5 and trying to sign/execute previous form" << std::endl;
		std::cout << "The form will be occur an error on sign but the bureaucrat will able to execute it" << std::endl;

		Bureaucrat	bureaucrat3("AnteDEGUEMON", 5);

		bureaucrat3.signForm(presidentialPardonForm);
		bureaucrat3.executeForm(presidentialPardonForm);
		}
	catch (std::exception &e)
	{
		printError(e.what());
	}
}

void	testPresidential()
{
	testPresidentialValid();
	testPresidentialInvalid();
}

int	main()
{
	testShrubbery();
	std::cout << "---" << std::endl;
	std::cout << "---" << std::endl;
	std::cout << "---" << std::endl;
	testRobotomy();
	std::cout << "---" << std::endl;
	std::cout << "---" << std::endl;
	std::cout << "---" << std::endl;
	testPresidential();
	return (0);
}