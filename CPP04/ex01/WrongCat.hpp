#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal{
     public:
        WrongCat();
        ~WrongCat();
        WrongCat(const WrongCat& copy);
        void operator=(const WrongCat& other);
        
        std::string getType() const;
        void makeSound() const;
};

#endif