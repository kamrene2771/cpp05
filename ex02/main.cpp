#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));

	Bureaucrat low("Low", 150);
	Bureaucrat mid("Mid", 70);
	Bureaucrat high("High", 1);

	ShrubberyCreationForm shrub("home");
	RobotomyRequestForm robot("Bender");
	PresidentialPardonForm pardon("Arthur Dent");

	std::cout << "=== BUREAUCRATS ===" << std::endl;
	std::cout << low << std::endl;
	std::cout << mid << std::endl;
	std::cout << high << std::endl;

	std::cout << "\n=== FORMS ===" << std::endl;
	std::cout << shrub << std::endl;
	std::cout << robot << std::endl;
	std::cout << pardon << std::endl;

	std::cout << "\n=== SIGN TESTS ===" << std::endl;
	low.signForm(shrub);
	mid.signForm(shrub);

	low.signForm(robot);
	mid.signForm(robot);

	mid.signForm(pardon);
	high.signForm(pardon);

	std::cout << "\n=== EXECUTE UNSIGNED FORM ===" << std::endl;
	ShrubberyCreationForm unsignedShrub("garden");
	high.executeForm(unsignedShrub);

	std::cout << "\n=== EXECUTE WITH LOW GRADE ===" << std::endl;
	low.executeForm(shrub);
	mid.executeForm(robot);

	std::cout << "\n=== VALID EXECUTIONS ===" << std::endl;
	high.executeForm(shrub);
	high.executeForm(robot);
	high.executeForm(pardon);

	return 0;
}