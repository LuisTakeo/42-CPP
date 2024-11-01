#ifndef INTERN_HPP
# define INTERN_HPP
# define QTD_FUNCTIONS 3

# include <iostream>
# include <string>
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& intern);
		~Intern();
		Intern& operator=(const Intern& intern);

		AForm* makeForm(const std::string& formName, const std::string& target) const;

		class FormNotFoundException: public std::exception
		{
			virtual const char* what() const throw();
		};
};

#endif