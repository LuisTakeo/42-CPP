#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default")
{
	this->_grade = 150;
}

Bureaucrat::Bureaucrat(std::string const name, int grade): _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &obj): _name(obj._name)
{
	this->_grade = obj._grade;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat	&   Bureaucrat::operator=(Bureaucrat const &obj)
{
	if (this != &obj)
		this->_grade = obj._grade;
	return (*this);
}

std::string const	Bureaucrat::getName() const
{
	return (this->_name);
}

int					Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade()
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		if (form.getSigned())
			throw Bureaucrat::CouldNotSignFormException("already signed");
		form.beSigned(*this);
	}
	catch (std::exception &e)
	{
		std::string error = "Bureaucrat " + this->_name + " cannot sign form "
			+ form.getName() + " because " + e.what();
		std::cerr << ERROR_COLOR << error.c_str() << RESET_COLOR << std::endl;
	}


}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

const char *	Bureaucrat::CouldNotSignFormException::getReason() const
{
	return (this->_reason.c_str());
}

Bureaucrat::CouldNotSignFormException::
	CouldNotSignFormException(const std::string &reason): _reason(reason)
{}

const char	*Bureaucrat::CouldNotSignFormException::what() const throw()
{

	return (this->_reason.c_str());
}

std::ostream	&operator<<(std::ostream &outstream, Bureaucrat const &obj)
{
	outstream << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (outstream);
}