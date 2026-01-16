#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;

protected:

public:
    Bureaucrat(const std::string &name, int grade);
    ~Bureaucrat();
    const std::string &getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    class GradeTooHighException : public std::exception
    {
    public:
        GradeTooHighException(const std::string &msg);
        const char *what() const throw();
        ~GradeTooHighException() throw() {}
    private:
        std::string message;
    };

    class GradeTooLowException : public std::exception
    {
    public:
        GradeTooLowException(const std::string &msg);
        const char *what() const throw();
        ~GradeTooLowException() throw() {}
    private:
        std::string message;
    };
};

#endif