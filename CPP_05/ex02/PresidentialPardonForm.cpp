#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("PresidentialPardonForm", 25, 5), _target("Default")
{
    std::cout << "A PresidentialPardonForm constructor for " << _target << "was called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << "A PresidentialPardonForm constructor for " << _target << "was called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src ) : AForm(src.getName(), src.getGradeToSign(), src.getGradeToExecute())
{
    std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
    _target = src.getTarget();
}

PresidentialPardonForm & PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
    _target = rhs.getTarget();
    std::cout << "PresidentialPardonForm Copy assignment operator called" << std::endl;

    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    try
    {
        if (getStatus() == false)
            throw AForm::UnsignedExeption();
        else if (executor.getGrade() > getGradeToExecute())
            throw AForm::ExecuteExepption();
        std::cout << getTarget() << " was forgiven by Zaphod Beeblebrox." << std::endl;
    }
    catch (AForm::UnsignedExeption & e)
    {
        std::cout << "The Form isn't signed." << std::endl;
        throw AForm::ExecuteExepption();
    }
}

std::string PresidentialPardonForm::getTarget( void ) const
{
    return (_target);
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
    std::cout << "A PresidentialPardonForm destructor for " << _target << "was called." << std::endl;
}