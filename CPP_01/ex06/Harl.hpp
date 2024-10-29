#ifndef HARL_HPP
#define HARL_HPP

// include //

#include <iostream>
#include <string>

// define //

# define DEBUG "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !"
# define INFO "I cannot believe adding extra bacon costs more money.\nYou didn\'t put enough bacon in my burger ! If you did, I wouldn\'t be asking for more !"
# define WARNING "I think I deserve to have some extra bacon for free.\nI\'ve been coming for years whereas you started working here since last month."
# define ERROR "This is unacceptable ! I want to speak to the manager now."
# define RETRY "HARL DIDN'T RECOGNIZE THE LEVEL, PLEASE RETRY :\n"

# define LEVEL1 "[\033[1;33mDEBUG\033[0;0m]"
# define LEVEL2 "[\033[1;36mINFO\033[0;0m]"
# define LEVEL3 "[\033[1;31mWARNING\033[0;0m]"
# define LEVEL4 "[\033[1;35mERROR\033[0;0m]"

// class //

class Harl 
{
    private :
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );


    public :
        int stat = 0;
        Harl( void );
        void complain( std::string level );
        ~Harl();

};

#endif