#ifndef WRONGCAT_CLASS_HPP
#define WRONGCAT_CLASS_HPP

#include "WrongAnimal.Class.hpp"

class WrongCat : public WrongAnimal
{
    public :
        WrongCat();
        ~WrongCat();
        virtual void makeSound();

};

#endif