#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "An insignificant Intern constructor was called" << std::endl;
}

Intern::Intern( Intern const & src )
{
    (void)src;
    std::cout << "An copy constructor for Intern was called" << std::endl;
}

static AForm  *NewPresidentForm( std::string target )
{
    AForm *NewForm = new PresidentialPardonForm(target);
    return (NewForm);
}

static AForm     *NewRobotomyForm( std::string target )
{
    AForm *NewForm = new RobotomyRequestForm(target);
    return (NewForm);
}

static AForm   *NewShrubberyForm( std::string target )
{
    AForm *NewForm = new ShrubberyCreationForm(target);
    return (NewForm);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
    std::string TypeForm[6] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm", "presidential pardon" ,"robotomy request", "shrubbery creation"};
    AForm	*(*CreateForm[3])(std::string target) = {NewPresidentForm, NewRobotomyForm, NewShrubberyForm};
    AForm    *NewForm = NULL;

    for (int i = 0; i < 6; i++)
    {
        if (TypeForm[i] == name)
            NewForm = (CreateForm[i % 3])(target);
    }
    if (NewForm == NULL)
    {
        std::cout << "Unknown Form, please can't give a true Form name for this insignificant Intern" << std::endl;
    }
    return (NULL);
}

Intern::~Intern()
{
    std::cout << "An insignificant Intern desstructor was called" << std::endl;
}