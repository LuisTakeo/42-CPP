#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():
	AForm("RobotomyRequestForm", 72, 45, "default")
{	}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm("RobotomyRequestForm", 72, 45, target)
{	}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other):
	AForm(other)
{	*this = other;	}

RobotomyRequestForm::~RobotomyRequestForm()
{	}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw RobotomyRequestForm::GradeTooLowException();
	if (!this->getSigned())
		throw RobotomyRequestForm::AFormNotSigned();

	if (std::rand() % 2)
		std::cout << this->getTarget() << " has been robotomized successfully! =')" << std::endl;
	else
		std::cout << this->getTarget() << " has been failed ='(" << std::endl;
}