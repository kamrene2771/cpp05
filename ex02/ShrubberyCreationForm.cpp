#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), _target(other._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

const std::string &ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream	outfile((this->_target + "_shrubbery").c_str());

	if (!outfile)
		throw std::runtime_error("could not open shrubbery file");

	outfile << "       _-_" << std::endl;
	outfile << "    /~~   ~~\\ " << std::endl;
	outfile << " /~~         ~~\\ " << std::endl;
	outfile << "{               }" << std::endl;
	outfile << " \\  _-     -_  /" << std::endl;
	outfile << "   ~  \\\\ //  ~" << std::endl;
	outfile << "_- -   | | _- _" << std::endl;
	outfile << "  _ -  | |   -_" << std::endl;
	outfile << "      // \\\\" << std::endl;
}