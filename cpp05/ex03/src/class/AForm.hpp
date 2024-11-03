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
		/*
		* @brief Constructor with parameters
		* @param name The name of the form
		* @param gradeToSign The grade to sign the form
		* @param gradeToExecute The grade to execute the form
		* @param target The target of the form
		*/
		AForm(std::string const name, int const gradeToSign,
			int const gradeToExecute, std::string const target);
		AForm(AForm const &otherAForm);
		virtual ~AForm();

		AForm &operator=(AForm const &otherAForm);

		std::string const	getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		std::string const 	getTarget() const;

		void				beSigned(Bureaucrat const &bureaucrat);
		virtual void		execute(Bureaucrat const &executor) const = 0;

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

		class AFormNotSigned : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};

std::ostream &operator<<(std::ostream &outstream, AForm const &form);

#endif