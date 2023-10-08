#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;

    public:
        ShrubberyCreationForm( void ) ;
        ShrubberyCreationForm( std::string target ) ;
        ShrubberyCreationForm( ShrubberyCreationForm const & src ) ;

        ShrubberyCreationForm & operator=( ShrubberyCreationForm const & rhs ) ;

        void execute(Bureaucrat const & executor) const ;

        std::string getTarget( void ) const ;

        ~ShrubberyCreationForm( void ) ;
};

#endif