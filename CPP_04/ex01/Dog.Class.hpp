#ifndef DOG_CLASS_HPP
#define DOG_CLASS_HPP

#include "Animal.Class.hpp"
#include "Brain.Class.hpp"

class Dog : public Animal
{
    private:
        Brain* DogBrain;

    public :
        Dog();
        ~Dog();
        virtual void makeSound() const;
};

#endif