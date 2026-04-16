#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "==== VALID TESTS ====" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 50);
		Bureaucrat tom("Tom", 140);

		Form taxForm("TaxForm", 100, 50);
		Form secretForm("SecretForm", 30, 10);

		std::cout << bob << std::endl;
		std::cout << tom << std::endl;
		std::cout << taxForm << std::endl;
		std::cout << secretForm << std::endl;

		tom.signForm(taxForm);
		bob.signForm(taxForm);
		bob.signForm(secretForm);

		std::cout << taxForm << std::endl;
		std::cout << secretForm << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n==== INVALID FORM TESTS ====" << std::endl;
	try
	{
		Form bad1("Bad1", 0, 50);
		std::cout << bad1 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Form bad2("Bad2", 50, 151);
		std::cout << bad2 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n==== INVALID BUREAUCRAT TEST ====" << std::endl;
	try
	{
		Bureaucrat chief("Chief", 0);
		std::cout << chief << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}