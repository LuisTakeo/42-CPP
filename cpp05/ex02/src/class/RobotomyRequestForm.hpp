#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <fstream>
# include <exception>
# include <cstdlib>

# include "AForm.hpp"


/*
* @brief RobotomyRequestForm class
* @details A form to robotomize a target
* @attention The grade to sign is 72 and the grade to execute is 45
*/
class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const target);
		RobotomyRequestForm(RobotomyRequestForm const &otherRobotomyRequestForm);
		virtual ~RobotomyRequestForm();

		RobotomyRequestForm &operator=(RobotomyRequestForm const &otherRobotomyRequestForm);

		void	execute(Bureaucrat const &executor) const;

};

#endif