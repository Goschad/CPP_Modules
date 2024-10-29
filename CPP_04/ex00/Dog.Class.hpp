#ifndef DOG_CLASS_HPP
#define DOG_CLASS_HPP

#include "Animal.Class.hpp"

class Dog : public Animal
{
    public :
        Dog();
        ~Dog();
        virtual void makeSound() const;
};

#endif