#include "Harl.hpp"

Harl::Harl( void )
{

}

void Harl::debug( void )
{
    std::cout<<"[\033[1;33mDEBUG\033[0;0m]\n"<<std::endl;
    std::cout<< DEBUG <<std::endl;
}

void Harl::info( void )
{
    std::cout<<"[\033[1;36mINFO\033[0;0m]\n"<<std::endl;
    std::cout<< INFO <<std::endl;
}

void Harl::warning( void )
{
    std::cout<<"[\033[1;31mWARNING\033[0;0m]\n"<<std::endl;
    std::cout<< WARNING <<std::endl;
}

void Harl::error( void )
{
    std::cout<<"[\033[1;35mERROR\033[0;0m]\n"<<std::endl;
    std::cout<< ERROR <<std::endl;
}

void Harl::complain( std::string level )
{
    std::string HarlLevels[8] = {"DEBUG", "INFO", "WARNING", "ERROR", "debug", "info", "warning", "error"};

    void    (Harl::*harl[4])( void ) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (int i = 0; i < 8; i++)
    {
        if (HarlLevels[i] == level)
        {
            if (i > 3)
                i -= 4;
            (this->*harl[i])();
            this->stat = 1;
            return ;
        }
    }
    std::cout << "HARL DIDN'T RECOGNIZE THE LEVEL, PLEASE RETRY"<<std::endl;;
    return ;
}

Harl::~Harl()
{
    
}