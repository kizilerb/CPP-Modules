#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal{
     private:
        Brain *dogBrain;

     public:
        Dog();
        ~Dog();
        Dog(const Dog& copy);
        Dog& operator=(const Dog& copy);
        
        std::string getType() const;
        void makeSound() const;

};

#endif