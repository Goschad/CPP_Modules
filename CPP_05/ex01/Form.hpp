#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool              _status;
        const int               _grade_to_sign;
        const int               _grade_to_execute;

    public:
        Form( void ) ;
        Form( Form const & src ) ;
        Form( std::string name, int grade_to_sign, int grade_to_execute ) ;

    void beSigned( Bureaucrat & bur );

    Form & operator=( Form const & rhs ) ;

    std::string getName( void ) const ;
    bool getStatus( void ) const ;
    int getGradeToExecute( void ) const ;
    int getGradeToSign( void ) const ;
    void getInfo( void ) const ;

    ~Form( void );

    class FormException : public std::exception
    {
        virtual const char* what() const throw()
        {
            return ("Form Grade Too Low Exception");
        }
    };

    class GradeTooLowException : public Form::FormException
    {
        virtual const char* what() const throw()
        {
            return ("Form Grade Exception");
        }
    };

    class GradeTooHighException : public Form::FormException
    {
        virtual const char* what() const throw()
        {
            return ("Form Grade Too High Exception");
        }
    };
};

std::ostream & operator<<( std::ostream & ostream , Form const & rhs) ;

#endif