#ifndef FORM_HPP
#define FORM_HPP            
#include <string>
#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"
class Form
{
private:
    const std::string _name;        
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;      
protected:          
public:
    Form(const std::string &name, int gradeToSign, int gradeToExecute);
    ~Form();
    const std::string &getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(const Bureaucrat &bureaucrat);

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