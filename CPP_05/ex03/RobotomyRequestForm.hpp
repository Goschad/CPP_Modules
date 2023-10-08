#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class AForm;

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
        
    public:
        RobotomyRequestForm( void ) ;
        RobotomyRequestForm( std::string target ) ;
        RobotomyRequestForm( RobotomyRequestForm const & src ) ;

        RobotomyRequestForm & operator=( RobotomyRequestForm const & rhs ) ;

        void execute(Bureaucrat const & executor) const ;

        std::string getTarget( void ) const ;

        ~RobotomyRequestForm() ;
};

#endif