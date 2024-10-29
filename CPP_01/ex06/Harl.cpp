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
    std::string HarlLevels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    void    (Harl::*harl[4])( void ) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (int i = 0; i < 4; i++)
    {
        if (HarlLevels[i] == level)
        {
            switch (i)
            {
                case 0:
                    (this->*harl[i++])();
                case 1:
                    (this->*harl[i++])();
                case 2:
                    (this->*harl[i++])();
                case 3:
                    (this->*harl[i++])();
                    break;
                default:
                    break;
            }
            return ;
        }
    }
    std::cout << "HARL DIDN'T RECOGNIZE THE LEVEL."<<std::endl;;
    return ;
}

Harl::~Harl()
{
    
}