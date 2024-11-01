#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& intern)
{
	this->operator=(intern);
}

Intern::~Intern()
{
}

Intern& Intern::operator=(const Intern& intern)
{
	(void)intern;
	return (*this);
}

AForm	*Intern::makeForm(const std::string &form, const std::string &target) const
{
	std::string	forms[QTD_FUNCTIONS] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	int			i;

	for (i = 0; i < QTD_FUNCTIONS; i++)
	{
		if (!form.compare(forms[i]))
			break;
	}
	switch (i)
	{
		case 0:
			std::cout << "Intern creates " << form << std::endl;
			return new PresidentialPardonForm(target);
		case 1:
			std::cout << "Intern creates " << form << std::endl;
			return new RobotomyRequestForm(target);
		case 2:
			std::cout << "Intern creates " << form << std::endl;
			return new ShrubberyCreationForm(target);
		default:
			throw FormNotFoundException();
	}
}

const char* Intern::FormNotFoundException::what() const throw()
{
	return "Intern cannot bring the form";
}
