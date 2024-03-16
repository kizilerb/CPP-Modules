#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
    this->type = "";
    std::cout << "WrongAnimal Default Constructor is called." << std::endl;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal Destructor is called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy){
    *this = copy;
    std::cout << "WrongAnimal Copy constructor is called." << std::endl;
}

void WrongAnimal::operator=(const WrongAnimal& other){
    this->type = other.type;
}

std::string WrongAnimal::getType() const{
    return this->type;
}

void WrongAnimal::makeSound() const{
    std::cout << "WrongAnimal sound!" << std::endl;
}