#include "Cat.hpp"

Cat::Cat(){
    this->type = "Cat";
    std::cout << "Cat Default Constructor is called." << std::endl;
}

Cat::~Cat(){
    std::cout << "Cat Destructor is called." << std::endl;
}

Cat::Cat(const Cat& copy){
    *this = copy;
    std::cout << "Cat Copy constructor is called." << std::endl;
}

void Cat::operator=(const Cat& other){
    this->type = other.type;
}

std::string Cat::getType() const{
    return this->type;
}

void Cat::makeSound() const{
    std::cout << "Meowww!" << std::endl;
}