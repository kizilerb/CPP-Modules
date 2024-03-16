#include "Dog.hpp"

Dog::Dog(){
    this->type = "Dog";
    std::cout << "Dog Default Constructor is called." << std::endl;
}

Dog::~Dog(){
    std::cout << "Dog Destructor is called." << std::endl;
}

Dog::Dog(const Dog& copy){
    *this = copy;
    std::cout << "Dog Copy constructor is called." << std::endl;
}

Dog& Dog::operator=(const Dog& copy){
    std::cout << "Copy assignment operator called" << std::endl;
    if(this == &copy)
        return *this;

    Brain* deepCopy = new Brain();
    this->type = copy.type;
    for(int i = 0; i < 100; i++)
        deepCopy->setIdeas(i, copy.dogBrain->getIdeas(i));
    this->dogBrain = deepCopy;
    return *this;
}

std::string Dog::getType() const{
    return this->type;
}

void Dog::makeSound() const{
    std::cout << "Woof Woof!" << std::endl;
}