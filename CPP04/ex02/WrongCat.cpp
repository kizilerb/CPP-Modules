#include "WrongCat.hpp"

WrongCat::WrongCat(){
    this->type = "WrongCat";
    std::cout << "WrongCat Default Constructor is called." << std::endl;
}

WrongCat::~WrongCat(){
    std::cout << "WrongCat Destructor is called." << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy){
    *this = copy;
    std::cout << "WrongCat Copy constructor is called." << std::endl;
}

void WrongCat::operator=(const WrongCat& other){
    this->type = other.type;
}

std::string WrongCat::getType() const{
    return this->type;
}

void WrongCat::makeSound() const{
    std::cout << "Meowww!" << std::endl;
}