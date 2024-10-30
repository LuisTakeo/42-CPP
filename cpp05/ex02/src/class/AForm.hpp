#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const _name;
		std::string const _target;
		bool			_signed;
		int const		_gradeToSign;
		int const		_gradeToExecute;

	public:
		AForm();
		AForm(std::string const name, int const gradeToSign,
			int const gradeToExecute, std::string const target);
		AForm(AForm const &otherAForm);
		~AForm();

		AForm &operator=(AForm const &otherAForm);

		std::string const	getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		std::string const 	getNameJogador() const;
		std::string const 	getTarget() const;

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

		class AFormAlreadySigned : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};

std::ostream &operator<<(std::ostream &outstream, AForm const &form);

#endif