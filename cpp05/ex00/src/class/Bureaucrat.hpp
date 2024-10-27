#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
# include <exception>


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

std::ostream	&operator<<(std::ostream &outstream, Bureaucrat const &obj);

#endif