#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	protected:
		AForm();
		AForm(const std::string &name, int gradeToSign, int gradeToExecute);

	public:
		AForm(const AForm &other);
		virtual ~AForm();

		AForm &operator=(const AForm &other);

		const std::string	&getName() const;
		bool				isSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		void	beSigned(Bureaucrat const &bureaucrat);
		void	execute(Bureaucrat const &executor) const;
		virtual void executeAction() const = 0;

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

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif