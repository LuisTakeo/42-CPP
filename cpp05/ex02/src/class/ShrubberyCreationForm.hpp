#ifndef SHUBBERYCREATIONFORM_HPP
# define SHUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include <exception>

# include "AForm.hpp"

class AForm;

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const target);
		ShrubberyCreationForm(ShrubberyCreationForm const &otherShrubberyCreationForm);
		~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &otherShrubberyCreationForm);

		void	execute(Bureaucrat const &executor) const;

		class CouldNotCreateFileException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

#endif