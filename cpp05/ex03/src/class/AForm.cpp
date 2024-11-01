#include "AForm.hpp"

# define ERROR_COLOR		"\033[1;31m"
# define TITLE_FORM_COLOR	"\033[1;35m"
# define SUCCESS_COLOR		"\033[1;32m"
# define RESET_COLOR		"\033[0m"

AForm::AForm(): _name("default"), _gradeToSign(150), _gradeToExecute(150)
{
	this->_signed = false;
}

AForm::AForm(std::string const name, int const gradeToSign,
			int const gradeToExecute, std::string const target):
	_name(name), _target(target), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	this->_signed = false;
}

AForm::AForm(AForm const &otherAForm):
	_name(otherAForm._name), _gradeToSign(otherAForm._gradeToSign),
	_gradeToExecute(otherAForm._gradeToExecute)
{
	if (this != &otherAForm)
		this->_signed = otherAForm._signed;
}

AForm::~AForm()
{
}

AForm &AForm::operator=(AForm const &otherAForm)
{
	if (this != &otherAForm)
	{
		this->_signed = otherAForm._signed;
	}
	return *this;
}

std::string const	AForm::getName() const
{
	return this->_name;
}

bool				AForm::getSigned() const
{
	return this->_signed;
}

int					AForm::getGradeToSign() const
{
	return this->_gradeToSign;
}

int					AForm::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

void				AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	if (this->_signed)
		throw AForm::AFormAlreadySigned();
	this->_signed = true;
	std::cout << "Bureaucrat " << bureaucrat.getName()
		<< " signed form " << this->_name << std::endl;
}

std::string const 	AForm::getTarget() const
{
	return this->_target;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high in Form";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low in Form";
}

const char *AForm::AFormAlreadySigned::what() const throw()
{
	return "Form is already signed";
}

const char *AForm::AFormNotSigned::what() const throw()
{
	return "Form is not signed";
}

std::ostream &operator<<(std::ostream &outstream, AForm const &form)
{
	outstream << TITLE_FORM_COLOR << "Form: " << form.getName() << RESET_COLOR << std::endl
		<< "Signed: " << (form.getSigned() ? "True" : "False") << std::endl
		<< "Grade to sign: " << form.getGradeToSign()  << std::endl
		<< "Grade to execute: " << form.getGradeToExecute() << std::endl;
	return outstream;
}