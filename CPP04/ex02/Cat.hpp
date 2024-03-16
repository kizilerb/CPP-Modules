#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal{
    private:
        Brain *catBrain;
    public:
        Cat();
        ~Cat();
        Cat(const Cat& copy);
        Cat& operator=(const Cat& copy);
        
        std::string getType() const;
        void makeSound() const;
};

#endif