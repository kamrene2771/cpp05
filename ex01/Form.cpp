#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150)
{
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other)
	: _name(other._name),
	  _signed(other._signed),
	  _gradeToSign(other._gradeToSign),
	  _gradeToExecute(other._gradeToExecute)
{
}

Form::~Form()
{
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		this->_signed = other._signed;
	return *this;
}

const std::string &Form::getName() const
{
	return this->_name;
}

bool Form::getSigned() const
{
	return this->_signed;
}

int Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

int Form::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	this->_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "form grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "form grade too low";
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form \"" << form.getName() << "\""
		<< ", signed: " << (form.getSigned() ? "yes" : "no")
		<< ", grade to sign: " << form.getGradeToSign()
		<< ", grade to execute: " << form.getGradeToExecute();
	return out;
}