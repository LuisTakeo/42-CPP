#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():
	AForm("ShrubberyCreationForm", 145, 137, "default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target):
	AForm("ShrubberyCreationForm", 145, 137, target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other):
	AForm(other)
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

// ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
// {
// 	if (this != &other)
// 	{
// 		this->_signed = other._signed;
// 	}
// 	return *this;
// }
