#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

#define TREE "         $\n        $$$\n       $$$$$\n      $$$$$$$\n     $$$$$$$$$\n    $$$$$$$$$$$\n   $$$$$$$$$$$$$\n  $$$$$$$$$$$$$$$\n $$$$$$$$$$$$$$$$$\n         |\n         |\n         |"

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool              _status;
        const int         _grade_to_sign;
        const int         _grade_to_execute;

    public:
        AForm( void ) ;
        AForm( AForm const & src ) ;
        AForm( std::string name, int grade_to_sign, int grade_to_execute ) ;

    void beSigned( Bureaucrat & bur ) ;
    virtual void execute(Bureaucrat const & executor) const = 0 ;

    AForm & operator=( AForm const & rhs ) ;

    std::string getName( void ) const ;
    bool getStatus( void ) const ;
    int getGradeToExecute( void ) const ;
    int getGradeToSign( void ) const ;
    void getInfo( void ) const ;

    virtual ~AForm( void ) = 0 ;

    class AFormException : public std::exception
    {
        virtual const char* what() const throw()
        {
            return ("Form Grade Exception");
        }
    };

    class GradeTooLowException : public AForm::AFormException
    {
        virtual const char* what() const throw()
        {
            return ("Form Grade is too Low Exception.");
        }
    };

    class GradeTooHighException : public AForm::AFormException
    {
        virtual const char* what() const throw()
        {
            return ("Form Grade is Too High Exception.");
        }
    };

    class ExecuteExepption : public AForm::AFormException
    {
        virtual const char* what() const throw()
        {
            return ("Form can't be executable Exception.");
        }
    };

    class SignedExepption : public AForm::AFormException
    {
        virtual const char* what() const throw()
        {
            return ("Form can't be signed Exception.");
        }
    };

    class UnsignedExeption : public AForm::AFormException
    {
        virtual const char* what() const throw()
        {
            return ("Form isn't signed.");
        }
    };
};

std::ostream & operator<<( std::ostream & ostream , AForm const & rhs) ;

#endif