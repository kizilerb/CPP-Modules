#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal{
     public:
        Cat();
        ~Cat();
        Cat(const Cat& copy);
        void operator=(const Cat& other);
        
        std::string getType() const;
        void makeSound() const;
};

#endif