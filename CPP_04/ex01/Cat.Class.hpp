#ifndef CAT_CLASS_HPP
#define CAT_CLASS_HPP

#include "Animal.Class.hpp"
#include "Brain.Class.hpp"

class Cat : public Animal
{
    private:
        Brain* CatBrain;

    public :
        Cat();
        void makeSound() const;
        ~Cat();

};

#endif