#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    Bureaucrat bur("GoodBureaucrat", 1);
    Bureaucrat bur2("FailBureaucrat", 150);

    PresidentialPardonForm test1("Booba");
    RobotomyRequestForm test2("Liam");
    ShrubberyCreationForm test3("Mojo");

    std::cout << "---------------------------------" << std::endl;

    test1.beSigned(bur2);

    std::cout << "---------------------------------" << std::endl;

    test1.beSigned(bur);
    test2.beSigned(bur);
    test3.beSigned(bur);

    bur2.executeForm(test1);

    std::cout << "---------------------------------" << std::endl;

    bur.executeForm(test1);

    std::cout << "---------------------------------" << std::endl;

    bur.executeForm(test2);

    std::cout << "---------------------------------" << std::endl;

    bur.executeForm(test3);

    std::cout << "---------------------------------" << std::endl;
}

