#ifndef WRONGANIMAL_CLASS_HPP
#define WRONGANIMAL_CLASS_HPP

#include <iostream>
#include <string>
#include <new>

class WrongAnimal
{
    protected :
        std::string type;

    public :
        WrongAnimal();
		virtual void    makeSound() const ;
        virtual std::string getType(void) const ;
        virtual ~WrongAnimal();
};

#endif