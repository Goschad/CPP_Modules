#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("Default")
{
    _grade = 150;
    std::cout << "An Default Bureaucrat was called with a grade of 150" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    _grade = grade;
    try
    {
        if (grade < 1)
            throw GradeTooHighException();
        else if (grade > 150)
            throw GradeTooLowException();
    }
    catch(const GradeTooHighException& e)
    {
        std::cout << "Grade Too Hight Exception" << std::endl;
        std::cout << "Default Low Grade Is 1" << std::endl;
        std::cout << std::endl;
        _grade = 1;
    }
    catch(const GradeTooLowException& e)
    {
        std::cout << "Grade Too Low Exception" << std::endl;
        std::cout << "Default Low Grade Is 150" << std::endl;
        std::cout << std::endl;
        _grade = 150;
    }

    std::cout << "An Default Bureaucrat named " << _name << " was called with a grade of " << _grade << std::endl;
}

Bureaucrat::Bureaucrat( Bureaucrat const & src ) : _name(src.getName() + "_copy")
{
    _grade = src.getGrade();
    std::cout << "Bureaucrat Copy constructor called" << std::endl;
}

void Bureaucrat::Promotion( void )
{
    _grade -= 1;
    try
    {
        if (_grade < 1)
            throw GradeTooHighException();
    }
    catch (const GradeTooHighException& e)
    {
        std::cout << std::endl;
        std::cout << "Grade Too Low Exception" << std::endl;
        std::cout << "Default Low Grade Is 1" << std::endl;
        std::cout << std::endl;
        _grade = 1;
    }
}

void Bureaucrat::Retrograde( void )
{
    _grade += 1;
    try
    {
        if (_grade > 150)
            throw GradeTooLowException();
    }
    catch(const GradeTooLowException& e)
    {
        std::cout << std::endl;
        std::cout << "Grade Too Low Exception" << std::endl;
        std::cout << "Default Low Grade Is 150" << std::endl;
        std::cout << std::endl;
        _grade = 150;
    }
}

void Bureaucrat::signForm( AForm & form )
{
    if ( form.getStatus() == false )
        std::cout << getName() << " couldn’t sign " << form.getName() << " because the form isn't signed." << std::endl;
    else if ( getGrade() > form.getGradeToSign() )
        std::cout << getName() << " couldn’t sign " << form.getName() << " because the Bureaucrat grade is too low." << std::endl;
    else if ( getGrade() <= form.getGradeToSign() && form.getStatus() == true )
        std::cout << getName() << " signed " << form.getName() << std::endl;
}

std::ostream & operator<<( std::ostream & ostream , Bureaucrat const & rhs)
{
	ostream << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	
	return (ostream);
}

Bureaucrat & Bureaucrat::operator=( Bureaucrat const & rhs )
{
    std::cout << "Bureaucrat Copy assignment operator called" << std::endl;
    _grade = rhs.getGrade();
    
    return (*this);
}

void Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << getName() << " executed " << form.getName() << std::endl;
    }
    catch(const AForm::ExecuteExepption& e)
    {
        std::cout << getName() << " can't executed " << form.getName() << std::endl;
    }
}

std::string Bureaucrat::getName( void ) const
{
    return (_name);
}

int Bureaucrat::getGrade( void ) const
{
    return (_grade);
}

void Bureaucrat::getInfo( void ) const
{
    std::cout << getName() << ", bureaucrat grade " << getGrade() << "." << std::endl;
}

Bureaucrat::~Bureaucrat( void )
{
    std::cout << "An destructor for Bureaucrat was called for " << _name << std::endl;
}