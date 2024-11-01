#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
	AForm("PresidentialPardonForm", 25, 5, "default")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
	AForm("PresidentialPardonForm", 25, 5, target)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other):
	AForm(other)
{	*this = other;	}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw PresidentialPardonForm::GradeTooLowException();
	if (!this->getSigned())
		throw PresidentialPardonForm::AFormNotSigned();

	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}