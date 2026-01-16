#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("Alice", 2);
        std::cout << b1.getName() << ", grade: " << b1.getGrade() << std::endl;

        b1.incrementGrade();
        std::cout << b1.getName() << ", grade: " << b1.getGrade() << std::endl;

        b1.incrementGrade(); 
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b2("Bob", 149);
        std::cout << b2.getName() << ", grade: " << b2.getGrade() << std::endl;

        b2.decrementGrade();
        std::cout << b2.getName() << ", grade: " << b2.getGrade() << std::endl;

        b2.decrementGrade(); 
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}