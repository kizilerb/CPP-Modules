#ifndef ANILMAL_HPP
#define ANILMAL_HPP

#include <iostream>

class Animal{
    protected:
        std::string type;
    public:
        Animal();
        virtual ~Animal();
        Animal(const Animal& copy);
        void operator=(const Animal& other);
        
        std::string getType() const;
        virtual void makeSound() const;
};


#endif