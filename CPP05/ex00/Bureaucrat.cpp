#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Default") {
    this->grade = 150;
    std::cout<< "Default constructor is called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string namein, int gradein): name(namein) {
    std::cout<< "Constructor is called." << std::endl;
    
    
}