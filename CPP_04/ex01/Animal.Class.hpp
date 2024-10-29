#ifndef ANIMAL_CLASS_HPP
#define ANIMAL_CLASS_HPP

#include <iostream>
#include <string>
#include <new>

class Animal
{
    protected :
        std::string type;

    public :
        Animal();
		virtual void    makeSound() const ;
        virtual std::string getType(void) const ;
        ~Animal();
};

#endif