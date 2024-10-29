#ifndef CAT_CLASS_HPP
#define CAT_CLASS_HPP

#include "Animal.Class.hpp"

class Cat : public Animal
{
    public :
        Cat();
        ~Cat();
        virtual void makeSound() const;

};

#endif