#include "Brain.hpp"

Brain::Brain(){
    for(int i = 0; i < 100; i++){
        std::stringstream ss;
        ss << "alp_" << i;
        this->ideas[i] = ss.str();
    }
    std::cout << "Brain Default Constructor called" << std::endl;
}

Brain::Brain(const Brain& copy){
    std::cout << "Brain Copy constructor called" << std::endl;
    *this = copy;
}

Brain& Brain::operator=(const Brain& copy){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &copy) {
        for (int i = 0; i < 100; ++i)
            this->ideas[i].append(copy.ideas[i]);
    }
    return *this;
}

Brain::~Brain(){
    std::cout << "Brain Destructor called" << std::endl;
}

const std::string* Brain::getIdeas() const{
    return ideas;
}

std::string Brain::getIdeas(int index) const{
    if (!this->ideas[index].empty())
        return this->ideas[index];
    return "";
}

void Brain::setIdeas(int index, const std::string& line){
    if (!line.empty())
        this->ideas[index].assign(line);
}