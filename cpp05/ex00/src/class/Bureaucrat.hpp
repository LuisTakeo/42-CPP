#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

# define ERROR_COLOR	"\033[1;31m"
# define TITLE_COLOR	"\033[1;34m"
# define RESET_COLOR	"\033[0m"

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
};

#endif