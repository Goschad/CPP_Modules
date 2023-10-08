#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;

    public:
        PresidentialPardonForm( void ) ;
        PresidentialPardonForm( std::string target ) ;
        PresidentialPardonForm( PresidentialPardonForm const & src ) ;

        PresidentialPardonForm & operator=( PresidentialPardonForm const & rhs ) ;

        void execute(Bureaucrat const & executor) const ;

        std::string getTarget( void ) const ;

        ~PresidentialPardonForm() ;
};

#endif