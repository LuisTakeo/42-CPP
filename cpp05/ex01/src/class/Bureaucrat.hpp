#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

# include "Form.hpp"

# define ERROR_COLOR	"\033[1;31m"
# define TITLE_COLOR	"\033[1;34m"
# define SUCCESS_COLOR	"\033[1;32m"
# define RESET_COLOR	"\033[0m"
# define SUBTITLE_COLOR	"\033[1;39m"

class	Form;

class	Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &obj);
		~Bureaucrat();

		Bureaucrat			&operator=(Bureaucrat const &obj);

		void				incrementGrade();
		void				decrementGrade();
		std::string const	getName() const;
		int					getGrade() const;
		void				signForm(Form &form);

		class	GradeTooHighException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class	GradeTooLowException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class	CouldNotSignFormException: public std::exception
		{
			private:
				const std::string			&_reason;
			public:
				CouldNotSignFormException(const std::string &reason);
				virtual const char	*what() const throw();
				const char			*getReason() const;
		};
};

std::ostream	&operator<<(std::ostream &outstream, Bureaucrat const &obj);

#endif