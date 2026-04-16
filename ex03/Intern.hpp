#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

class AForm;

class Intern
{
	private:
		typedef AForm* (Intern::*FormCreator)(const std::string &target) const;

		AForm	*createShrubberyForm(const std::string &target) const;
		AForm	*createRobotomyForm(const std::string &target) const;
		AForm	*createPresidentialForm(const std::string &target) const;

	public:
		Intern();
		Intern(const Intern &other);
		~Intern();

		Intern &operator=(const Intern &other);

		AForm	*makeForm(const std::string &formName, const std::string &target) const;
};

#endif