#ifndef WRONGANILMAL_HPP
#define WRONGANILMAL_HPP

#include <iostream>

class WrongAnimal{
    protected:
        std::string type;
    public:
        WrongAnimal();
        ~WrongAnimal();
        WrongAnimal(const WrongAnimal& copy);
        void operator=(const WrongAnimal& other);
        
        std::string getType() const;
        void makeSound() const;
};


#endif