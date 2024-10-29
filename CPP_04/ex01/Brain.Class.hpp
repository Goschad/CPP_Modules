#ifndef BRAIN_CLASS_HPP
#define BRAIN_CLASS_HPP

#include <iostream>
#include <string>

class Brain
{
    private :
        std::string ideas[100];

    public :
        Brain();
        std::string getAnIdeas( void ) const;
        ~Brain();
};

#endif