#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const _name;
		bool			_signed;
		int const		_gradeToSign;
		int const		_gradeToExecute;

	public:
		Form();
		Form(std::string const name, int const gradeToSign, int const gradeToExecute);
		Form(Form const &otherForm);
		~Form();

		Form &operator=(Form const &otherForm);

		std::string const	getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		void				beSigned(Bureaucrat const &bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};

std::ostream &operator<<(std::ostream &outstream, Form const &form);

#endif