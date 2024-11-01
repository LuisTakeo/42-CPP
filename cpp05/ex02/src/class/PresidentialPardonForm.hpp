#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <fstream>
# include <exception>

# include "AForm.hpp"

/*
* @brief PresidentialPardonForm class
* @details A form to pardon a target
* @attention The grade to sign is 25 and the grade to execute is 5
*/
class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const target);
		PresidentialPardonForm(PresidentialPardonForm const &otherPresidentialPardonForm);
		virtual ~PresidentialPardonForm();

		PresidentialPardonForm &operator=(PresidentialPardonForm const &otherPresidentialPardonForm);

		void	execute(Bureaucrat const &executor) const;
};

#endif