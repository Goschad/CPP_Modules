#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;

    public:
        Bureaucrat( void ) ;
        Bureaucrat( Bureaucrat const & src ) ;
        Bureaucrat( std::string name, int grade ) ;
        
        void Promotion( void ) ;
        void Retrograde( void ) ;
        void signForm( Form & form ) ;

        std::string getName( void ) const ;
        int getGrade( void ) const ;
        void getInfo( void ) const ;

        Bureaucrat & operator=( Bureaucrat const & rhs ) ;

        ~Bureaucrat( void ) ;

        class BureaucratException : public std::exception
    {
        virtual const char* what() const throw()
        {
            return ("Grade Exception");
        }
    };

    class GradeTooLowException : public Bureaucrat::BureaucratException
    {
        virtual const char* what() const throw()
        {
            return ("Grade Too Low Exception");
        }
    };

    class GradeTooHighException : public Bureaucrat::BureaucratException
    {
        virtual const char* what() const throw()
        {
            return ("Grade Too High Exception");
        }
    };
};

std::ostream & operator<<( std::ostream & ostream , Bureaucrat const & rhs) ;

#endif