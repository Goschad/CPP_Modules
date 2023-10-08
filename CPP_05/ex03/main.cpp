#include "Intern.hpp"

int main(void)
{
    Bureaucrat mf("MainCharacter", 1);

    Intern someRandomIntern;

    AForm* robot;
    AForm* pardon;
    AForm* shrubbery;

    pardon = someRandomIntern.makeForm("presidential pardon", "Macron");
    robot = someRandomIntern.makeForm("robotomy request", "Bender");
    shrubbery = someRandomIntern.makeForm("shrubbery creeation", "Mojo");

    if (pardon != NULL)
        pardon->beSigned(mf);
    if (robot != NULL)
        robot->beSigned(mf);
    if (shrubbery != NULL)
        shrubbery->beSigned(mf);

    std::cout << "---------------------------------" << std::endl;
    
    if (pardon != NULL)
        mf.executeForm(*pardon);

    std::cout << "---------------------------------" << std::endl;

    if (robot != NULL)
        mf.executeForm(*robot);

    std::cout << "---------------------------------" << std::endl;

    if (shrubbery != NULL)
        mf.executeForm(*shrubbery);

    std::cout << "---------------------------------" << std::endl;

    if (pardon != NULL)
        delete pardon;
    if (robot != NULL)
        delete robot;
    if (shrubbery != NULL)
        delete shrubbery;
}

