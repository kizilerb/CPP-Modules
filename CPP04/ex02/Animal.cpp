#include "Animal.hpp"

Animal::Animal(){
    this->type = "";
    std::cout << "Animal Default Constructor is called." << std::endl;
}

Animal::~Animal(){
    std::cout << "Animal Destructor is called." << std::endl;
}

Animal::Animal(const Animal& copy){
    *this = copy;
    std::cout << "Animal Copy constructor is called." << std::endl;
}

void Animal::operator=(const Animal& other){
    this->type = other.type;
}

std::string Animal::getType() const{
    return this->type;
}

