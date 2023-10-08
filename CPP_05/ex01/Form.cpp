#include "Form.hpp"

Form::Form( void ) : _name("Default"), _grade_to_sign(5), _grade_to_execute(1)
{
    _status = false;
    std::cout << "An Default Form was called" << std::endl;
}

Form::Form( std::string name, int grade_to_sign, int grade_to_execute ) : _name(name), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
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
    std::cout << "A Form named " << _name << " needed a grade of ";
    std::cout << _grade_to_sign << " to sign and " << _grade_to_execute << " to execute." << std::endl;
}

Form::Form( Form const & src ) : _name(src.getName() + "_copy"), _grade_to_sign(src.getGradeToSign()), _grade_to_execute(src.getGradeToExecute())
{
    _status = src.getStatus();
    std::cout << "Bureaucrat Copy constructor called" << std::endl;
}

void Form::beSigned( Bureaucrat & bur )
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
    }
}

Form & Form::operator=( Form const & rhs )
{
    _status = rhs.getStatus();
    std::cout << "Form Copy assignment operator called" << std::endl;

    return (*this);
}

std::ostream & operator<<( std::ostream & ostream , Form const & rhs)
{
    ostream << rhs.getName() << ", Form grade to sign " << rhs.getGradeToSign()
    << "and grade to execute " << rhs.getGradeToExecute() << "." << std::endl;
	
	return (ostream);
}

std::string Form::getName( void ) const
{
    return (_name);
}

int Form::getGradeToSign( void ) const
{
    return (_grade_to_sign);
}

int Form::getGradeToExecute( void ) const
{
    return (_grade_to_execute);
}

bool Form::getStatus( void ) const
{
    return (_status);
}

void Form::getInfo( void ) const
{
    std::cout << getName() << ", Form grade to sign " << getGradeToSign()
    << "and grade to execute " << getGradeToExecute() << "." << std::endl;
}

Form::~Form( void )
{
    std::cout << "An destructor for Form was called for " << _name << std::endl;
}