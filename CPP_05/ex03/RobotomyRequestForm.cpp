#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("RobotomyRequestForm", 72, 45), _target("Default")
{
    std::cout << "A RobotomyRequestForm constructor for " << _target << " was called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "A RobotomyRequestForm constructor for " << _target << " was called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src ) : AForm(src.getName(), src.getGradeToSign(), src.getGradeToExecute())
{
    std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
    _target = src.getTarget();
}

RobotomyRequestForm & RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
    _target = rhs.getTarget();
    std::cout << "RobotomyRequestForm Copy assignment operator called" << std::endl;

    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    try
    {
        if (getStatus() == false)
            throw AForm::UnsignedExeption();
        else if (executor.getGrade() > getGradeToExecute())
            throw AForm::ExecuteExepption();
        srand((unsigned int)time(NULL));
        std::cout << "*BiZ Biz*" << std::endl << "*Tic Zzzz*" << std::endl;
        if (rand() % 2 == 0)
            std::cout << getTarget() << " was successfully robotomised." << std::endl;
        else
            std::cout << getTarget() << " was unsuccessfully robotomised." << std::endl;
    }
    catch (AForm::UnsignedExeption & e)
    {
        std::cout << "The Form isn't signed." << std::endl;
        throw AForm::ExecuteExepption();
    }
}

std::string RobotomyRequestForm::getTarget( void ) const
{
    return (_target);
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
    std::cout << "A RobotomyRequestForm destructor for " << getTarget() << " was called." << std::endl;
}