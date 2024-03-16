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

Cat& Cat::operator=(const Cat& copy){
    std::cout << "Copy assignment operator called" << std::endl;
    if(this == &copy)
        return *this;

    Brain *deepCopy = new Brain();
    this->type = copy.type;
    for(int i = 0; i < 100; i++)
        deepCopy->setIdeas(i, copy.catBrain->getIdeas(i));
    this->catBrain = deepCopy;
    return *this;
}

void Cat::makeSound() const{
    std::cout << "Meowww!" << std::endl;
}