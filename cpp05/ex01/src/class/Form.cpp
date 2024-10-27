#include "Form.hpp"

# define ERROR_COLOR		"\033[1;31m"
# define TITLE_FORM_COLOR	"\033[1;35m"
# define SUCCESS_COLOR		"\033[1;32m"
# define RESET_COLOR		"\033[0m"

Form::Form(): _name("default"), _gradeToSign(150), _gradeToExecute(150)
{
	this->_signed = false;
}

Form::Form(std::string const name, int const gradeToSign, int const gradeToExecute):
	_name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	this->_signed = false;
}

Form::Form(Form const &otherForm):
	_name(otherForm._name), _gradeToSign(otherForm._gradeToSign),
	_gradeToExecute(otherForm._gradeToExecute)
{
	if (this != &otherForm)
		this->_signed = otherForm._signed;
}

Form::~Form()
{
}

Form &Form::operator=(Form const &otherForm)
{
	if (this != &otherForm)
	{
		this->_signed = otherForm._signed;
	}
	return *this;
}

std::string const	Form::getName() const
{
	return this->_name;
}

bool				Form::getSigned() const
{
	return this->_signed;
}

int					Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

int					Form::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

void				Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high in Form";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low in Form";
}

std::ostream &operator<<(std::ostream &outstream, Form const &form)
{
	outstream << TITLE_FORM_COLOR << "Form: " << form.getName() << RESET_COLOR << std::endl
		<< "Signed: " << (form.getSigned() ? "True" : "False") << std::endl
		<< "Grade to sign: " << form.getGradeToSign()  << std::endl
		<< "Grade to execute: " << form.getGradeToExecute() << std::endl;
	return outstream;
}