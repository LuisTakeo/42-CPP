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

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream	&operator<<(std::ostream &outstream, Bureaucrat const &obj)
{
	outstream << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (outstream);
}