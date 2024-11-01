#include "./ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():
	AForm("ShrubberyCreationForm", 145, 137, "default")
{ }

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target):
	AForm("ShrubberyCreationForm", 145, 137, target)
{ }

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other):
	AForm(other)
{	*this = other; }

ShrubberyCreationForm::~ShrubberyCreationForm()
{ }

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw ShrubberyCreationForm::GradeTooLowException();
	if (!this->getSigned())
		throw ShrubberyCreationForm::AFormNotSigned();

	std::string		filename = this->getTarget() + "_shrubbery";
	std::ofstream	file(filename.c_str());

	if (!file.is_open())
		throw ShrubberyCreationForm::CouldNotOpenFileException();
	file << "                                                         ." << std::endl
		 << "                                              .         ; " << std::endl
		 <<	"                 .              .              ;%     ;;   " << std::endl
		<<	"                   ,           ,                :;%  %;   " << std::endl
		<<	"                    :         ;                   :;%;'     .,   " << std::endl
		<<	"           ,.        %;     %;            ;        %;'    ,;" << std::endl
		<<	"             ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl
		<<	"              %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl
		<<	"               ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl
		<<	"                `%;.     ;%;     %;'         `;%%;.%;'" << std::endl
		<<	"                 `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl
		<<	"                    `:%;.  :;bd%;          %;@%;'" << std::endl
		<<	"                      `@%:.  :;%.         ;@@%;'  "  << std::endl
		<<	"                        `@%.  `;@%.      ;@@%;       "   << std::endl
		<<	"                          `@%%. `@%%    ;@@%;        " << std::endl
		<<	"                            ;@%. :@%%  %@@%;       " << std::endl
		<<	"                              %@bd%%%bd%%:;     " << std::endl
		<<	"                                #@%%%%%:;;" << std::endl
		<<	"                                %@@%%%::;" << std::endl
		<<	"                                %@@@%(o);  . '  "    << std::endl
		<<	"                                %@@@o%;:(.,'      "   << std::endl
		<<	"                            `.. %@@@o%::;         " << std::endl
		<<	"                               `)@@@o%::;         " << std::endl
		<<	"                                %@@(o)::;        " << std::endl
		<<	"                               .%@@@@%::;         " << std::endl
		<<	"                               ;%@@@@%::;.         "  << std::endl
		<<	"                              ;%@@@@%%:;;;. " << std::endl
		<<	"                          ...;%@@@@@%%:;;;;,.. " << std::endl;
	std::cout << "Bureaucrat " << executor.getName()
		<< " has been created a tree in "
		<< filename << std::endl;
	file.close();
}

// Exceptions
const char	*ShrubberyCreationForm::CouldNotCreateFileException::what() const throw()
{
	return "Could not create file";
}

const char	*ShrubberyCreationForm::CouldNotOpenFileException::what() const throw()
{
	return "Could not open file";
}
