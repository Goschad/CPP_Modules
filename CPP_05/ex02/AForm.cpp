#include "AForm.hpp"

AForm::AForm( void ) : _name("Default"), _grade_to_sign(5), _grade_to_execute(1)
{
    _status = false;
    std::cout << "An Default AForm was called" << std::endl;
}

AForm::AForm( std::string name, int grade_to_sign, int grade_to_execute ) : _name(name), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
    _status = false;
    try
    {
        if (_grade_to_execute < 1 || _grade_to_sign < 1)
            throw GradeTooHighException();
        if (_grade_to_execute > 150 || _grade_to_sign > 150)
            throw GradeTooLowException();
    }
    catch(const GradeTooHighException& e)
    {
        std::cout << "Grade ";
        if (_grade_to_execute < 1)
            std::cout << "to execute ";
        else if (_grade_to_sign < 1)
            std::cout << "to sign ";
        std::cout << "Too Hight Exception" << std::endl;
        std::cout << getName() << " is an " << "unusable Form" << std::endl;
        return ;
    }
    catch(const GradeTooLowException& e)
    {
        std::cout << "Grade ";
        if (_grade_to_execute > 150)
            std::cout << "to execute ";
        else if (_grade_to_sign > 150)
            std::cout << "to sign ";
        std::cout << "Too Low Exception" << std::endl;
        std::cout << getName() << " is an " << "unusable Form" << std::endl;
        return ;
    }
    std::cout << "A AForm named " << _name << " needed a grade of ";
    std::cout << _grade_to_sign << " to sign and " << _grade_to_execute << " to execute." << std::endl;
}

AForm::AForm( AForm const & src ) : _name(src.getName() + "_copy"), _grade_to_sign(src.getGradeToSign()), _grade_to_execute(src.getGradeToExecute())
{
    _status = src.getStatus();
    std::cout << "AForm Copy constructor called" << std::endl;
}

void AForm::beSigned( Bureaucrat & bur )
{
    try 
    {
        if (bur.getGrade() > getGradeToSign())
            throw GradeTooLowException();
        else
            _status = true;
    }
    catch (const GradeTooLowException& e)
    {
        std::cout << "Bureaucrat grade is to low" << std::endl;
        return ;
    }
}

AForm & AForm::operator=( AForm const & rhs )
{
    _status = rhs.getStatus();
    std::cout << "AForm Copy assignment operator called" << std::endl;

    return (*this);
}

std::ostream & operator<<( std::ostream & ostream , AForm const & rhs)
{
    ostream << rhs.getName() << ", AForm grade to sign " << rhs.getGradeToSign()
    << "and grade to execute " << rhs.getGradeToExecute() << "." << std::endl;
	
	return (ostream);
}

std::string AForm::getName( void ) const
{
    return (_name);
}

int AForm::getGradeToSign( void ) const
{
    return (_grade_to_sign);
}

int AForm::getGradeToExecute( void ) const
{
    return (_grade_to_execute);
}

bool AForm::getStatus( void ) const
{
    return (_status);
}

void AForm::getInfo( void ) const
{
    std::cout << getName() << ", AForm grade to sign " << getGradeToSign()
    << "and grade to execute " << getGradeToExecute() << "." << std::endl;
}

AForm::~AForm( void )
{
    std::cout << "An destructor for AForm was called for " << _name << std::endl;
}