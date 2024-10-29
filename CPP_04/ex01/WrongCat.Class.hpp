#ifndef WRONGCAT_CLASS_HPP
#define WRONGCAT_CLASS_HPP

#include "WrongAnimal.Class.hpp"
#include "Brain.Class.hpp"

class WrongCat : public WrongAnimal
{
    private :
        Brain* WrongCatBrain;

    public :
        WrongCat();
        ~WrongCat();
        virtual void makeSound();

};

#endif