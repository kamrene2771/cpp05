#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException("Grade is too high");
    if (grade > 150)
        throw GradeTooLowException("Grade is too low");
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::incrementGrade()
{
    if (_grade <= 1)
        throw GradeTooHighException("Grade is too high");
    _grade--;
}       

void Bureaucrat::decrementGrade()
{
    if (_grade >= 150)
        throw GradeTooLowException("Grade is too low");
    _grade++;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &msg) : std::exception(), message(msg) {}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return message.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &msg) : std::exception(), message(msg) {}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return message.c_str();
}