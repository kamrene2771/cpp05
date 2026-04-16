#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

AForm *Intern::createShrubberyForm(const std::string &target) const
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyForm(const std::string &target) const
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialForm(const std::string &target) const
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
	const std::string	names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	FormCreator creators[3] = {
		&Intern::createShrubberyForm,
		&Intern::createRobotomyForm,
		&Intern::createPresidentialForm
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == names[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*creators[i])(target);
		}
	}
	std::cout << "Intern couldn't create " << formName
			  << " because this form does not exist" << std::endl;
	return NULL;
}