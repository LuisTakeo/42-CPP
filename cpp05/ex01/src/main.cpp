#include "./main.hpp"

void	printError(std::string const &msg)
{
	std::cerr << ERROR_COLOR << "Error: " << msg << RESET_COLOR << std::endl;

}

void	testCreatingFormsValid()
{
	std::cout << TITLE_COLOR << "Creating forms with valid grades" << RESET_COLOR << std::endl;
	try
	{
		Form	form1("form1", 1, 1);
		Form	form2("form2", 150, 150);
		Form	form3(form2);
		Form	form4 = form1;

		std::cout << SUBTITLE_COLOR << "Declaring forms" << RESET_COLOR << std::endl;
		std::cout << form1;
		std::cout << form2;
		std::cout << form3;
		std::cout << form4;

		std::cout << SUBTITLE_COLOR << "Signing forms 1 and 2 with bureaurats "
			<< "with valid notes" << RESET_COLOR << std::endl;
		Bureaucrat	bureaucrat1("bureaucrat1", 1);
		std::cout << bureaucrat1 << std::endl;
		Bureaucrat	bureaucrat2("bureaucrat2", 150);
		std::cout << bureaucrat2 << std::endl;
		form1.beSigned(bureaucrat1);
		form2.beSigned(bureaucrat2);

		std::cout << SUBTITLE_COLOR << "Showing forms signed " << RESET_COLOR << std::endl;
		std::cout << form1;
		std::cout << form2;
		std::cout << form3;
		std::cout << form4;

		std::cout << SUCCESS_COLOR << "Finished" << RESET_COLOR << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		printError(e.what());
	}
	catch (Form::GradeTooLowException &e)
	{
		printError(e.what());
	}
	catch (std::exception &e)
	{
		printError(e.what());
	}
}

void	testTooHighGradeNegativeValue()
{
	std::cout << TITLE_COLOR << "Trying to declare form with negative grade" << RESET_COLOR << std::endl;
	try
	{
		Form	form1("form1", -1, -1);

		std::cout << TITLE_COLOR << "Declaring forms" << RESET_COLOR << std::endl;
		std::cout << form1;
	}
	catch (std::exception &e)
	{
		printError(e.what());
	}
}


void	testTooHighGradeValueZero()
{
	std::cout << TITLE_COLOR << "Trying to declare form with zero grade" << RESET_COLOR << std::endl;
	try
	{
		Form	form1("form1", 0, 0);

		std::cout << TITLE_COLOR << "Declaring forms" << RESET_COLOR << std::endl;
		std::cout << form1;
	}
	catch (Form::GradeTooHighException &e)
	{
		printError(e.what());
	}
	catch (Form::GradeTooLowException &e)
	{
		printError(e.what());
	}
	catch (std::exception &e)
	{
		printError(e.what());
	}
}

void	testTooLowSignedNote()
{
	std::cout << TITLE_COLOR << "Trying to sign form with too low grade" << RESET_COLOR << std::endl;
	try
	{
		std::cout << SUBTITLE_COLOR << "Declaring forms" << RESET_COLOR << std::endl;
		Form	form1("form1", 5, 5);
		Bureaucrat	bureaucrat1("bureaucrat1", 6);

		std::cout << form1;
		std::cout << bureaucrat1 << std::endl;

		std::cout << SUBTITLE_COLOR << "Trying to sign form" << RESET_COLOR << std::endl;
		form1.beSigned(bureaucrat1);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		printError(e.what());
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		printError(e.what());
	}
	catch (Form::GradeTooHighException &e)
	{
		printError(e.what());
	}
	catch (Form::GradeTooLowException &e)
	{
		printError(e.what());
	}
	catch (std::exception &e)
	{
		printError(e.what());
	}
}

void	testTooLowSignedNoteValue150()
{
	std::cout << TITLE_COLOR << "Trying to sign form with bureaucrat's too low grade (150)" << RESET_COLOR << std::endl;
	try
	{
		std::cout << SUBTITLE_COLOR << "Declaring forms" << RESET_COLOR << std::endl;
		Form	form1("form1", 5, 5);
		Bureaucrat	bureaucrat1("bureaucrat1", 150);

		std::cout << form1;
		std::cout << bureaucrat1 << std::endl;

		std::cout << SUBTITLE_COLOR << "Trying to sign form" << RESET_COLOR << std::endl;
		form1.beSigned(bureaucrat1);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		printError(e.what());
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		printError(e.what());
	}
	catch (Form::GradeTooHighException &e)
	{
		printError(e.what());
	}
	catch (Form::GradeTooLowException &e)
	{
		printError(e.what());
	}
	catch (std::exception &e)
	{
		printError(e.what());
	}
}

void	testTooLowGradeInForm()
{
	std::cout << TITLE_COLOR << "Trying to declare form with too low grade (151)" << RESET_COLOR << std::endl;
	try
	{
		Form	form1("form1", 151, 151);

		std::cout << form1;
	}
	catch (Form::GradeTooHighException &e)
	{
		printError(e.what());
	}
	catch (Form::GradeTooLowException &e)
	{
		printError(e.what());
	}
	catch (std::exception &e)
	{
		printError(e.what());
	}
}

void	testTooLowGradeValueOneThousand()
{
	std::cout << TITLE_COLOR << "Trying to declare form with too low grade (1000)" << RESET_COLOR << std::endl;
	try
	{
		Form	form1("form1", 1000, 1000);

		std::cout << SUBTITLE_COLOR << "Declaring forms" << RESET_COLOR << std::endl;
		std::cout << form1;
	}
	catch (std::exception &e)
	{
		printError(e.what());
	}
}

void	testInvalidFormTooLowGrade()
{
	std::cout << TITLE_COLOR << "Creating forms with too low grade" << RESET_COLOR << std::endl;
	testTooLowGradeInForm();
	testTooLowGradeValueOneThousand();
	testTooLowSignedNote();
	testTooLowSignedNoteValue150();
}

void	testInvalidFormTooHighGrade()
{
	std::cout << TITLE_COLOR << "Creating forms with too high grade" << RESET_COLOR << std::endl;
	testTooHighGradeValueZero();
	testTooHighGradeNegativeValue();
}

void	testCreatingFormsInvalid()
{
	testInvalidFormTooHighGrade();
	testInvalidFormTooLowGrade();
	std::cout << SUCCESS_COLOR << "Finished" << RESET_COLOR << std::endl;
}


void	test_forms()
{
	testCreatingFormsValid();
	testCreatingFormsInvalid();
}

int	main()
{
	test_forms();
	return (0);
}