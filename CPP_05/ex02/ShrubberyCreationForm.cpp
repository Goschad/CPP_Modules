#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("ShrubberyCreationForm", 145, 137)
{
    this->_target = "Default";
    std::cout << "A ShrubberyCreationForm constructor for " << _target << "was called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("ShrubberyCreationForm", 145, 137)
{
    this->_target = target;
    std::cout << "A ShrubberyCreationForm constructor for " << _target << "was called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src ) : AForm(src.getName(), src.getGradeToSign(), src.getGradeToExecute())
{
    std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
    _target = src.getTarget();
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
    _target = rhs.getTarget();
    std::cout << "ShrubberyCreationForm Copy assignment operator called" << std::endl;

    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    std::string shrubbery = TREE;

    try
    {
        if (getStatus() == false)
            throw AForm::UnsignedExeption();
        else if (executor.getGrade() > getGradeToExecute())
            throw AForm::ExecuteExepption();
        std::ofstream ofs(getTarget().append("_shrubbery").c_str());
        ofs << shrubbery;
        ofs.close();
    }
    catch (AForm::UnsignedExeption & e)
    {
        std::cout << "The Form isn't signed." << std::endl;
        throw AForm::ExecuteExepption();
    }
}

std::string ShrubberyCreationForm::getTarget( void ) const
{
    return (_target);
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
    std::cout << "A ShrubberyCreationForm destructor for " << getTarget() << "was called." << std::endl;
}