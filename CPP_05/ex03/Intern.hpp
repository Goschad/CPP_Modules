#ifndef INTER_HPP
#define INTER_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    private:
    
    public:
        Intern() ;
        Intern( Intern const & src ) ;

        AForm *makeForm(std::string name, std::string target) ;

        Intern & operator=( Intern const & rhs ) ;

        ~Intern() ;
};

#endif