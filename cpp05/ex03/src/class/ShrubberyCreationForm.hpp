#ifndef SHUBBERYCREATIONFORM_HPP
# define SHUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include <exception>

# include "AForm.hpp"

// class AForm;
/*
* @brief ShrubberyCreationForm class
* @details A form to create a file with a tree
* @attention The grade to sign is 145 and the grade to execute is 137
*/
class ShrubberyCreationForm: public AForm
{
	public:
		// CONSTRUCTORS | DESTRUCTOR
		/*
		* @brief Default constructor
		*/
		ShrubberyCreationForm();
		/*
		* @brief Constructor with parameter
		* @param target The target of the form
		* @attention The grade to sign is 145 and the grade to execute is 137
		*/
		ShrubberyCreationForm(std::string const target);
		/*
		* @brief Copy constructor
		* @param otherShrubberyCreationForm The ShrubberyCreationForm to copy. It will copy the target and the grade
		*/
		ShrubberyCreationForm(ShrubberyCreationForm const &otherShrubberyCreationForm);
		/*
		* @brief Destructor
		*/
		virtual ~ShrubberyCreationForm();
		// IT SHOULD BE VIRTUAL
		// OPERATORS
		/*
		* @brief Assignation operator= for ShrubberyCreationForm
		* @param otherShrubberyCreationForm The ShrubberyCreationForm to copy
		* @return The new ShrubberyCreationForm
		*/
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &otherShrubberyCreationForm);

		/*
		* @LuisTakeo
		* @brief Execute the form. It will create a file with the target name
		*
		* @attention To execute the form, the following conditions must be met:
		* @attention - Grade of the bureaucrat must be higher than the grade to execute the form
		* @attention - The form must be signed
		* @brief The file will be created with the target name
		* @param executor The bureaucrat who will execute the form
		*
		* @exception AFormAlreadySigned The form is already signed
		* @exception GradeTooLowException The grade of the bureaucrat is too low
		* @exception CouldNotCreateFileException The file could not be created
		* @exception CouldNotOpenFileException The file could not be opened
		*/
		void	execute(Bureaucrat const &executor) const;

		// EXCEPTIONS
		/*
		* @brief Exception when the file could not be created
		*/
		class CouldNotCreateFileException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		/*
		* @brief Exception when the file could not be opened
		*/
		class CouldNotOpenFileException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

#endif