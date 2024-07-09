#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Default") {
    this->grade = 150;
    std::cout<< "Default constructor is called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string namein, int gradein): name(namein) {
    std::cout<< "Constructor is called." << std::endl;
    try{
        setGrade(gradein);
    }
    catch(std::exception& e){
        std::cout << e.what() << std::endl;
        std::cout << "Lowest value which is 150 is set as default" << std::endl;
        this->grade = 150;
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy): name(copy.name), grade(copy.grade) {
    std::cout << "Copy constructor is called." << std::endl;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Dectructor is called." << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy){
    std::cout << "Copy assignment operator called" << std::endl;
    if(this == &copy)
        return *this;
	this->grade = copy.grade;
    return *this;
}

std::string Bureaucrat::getName()const {
    return this->name;
}

int Bureaucrat::getGrade()const {
    return this->grade;
}

void Bureaucrat::increaseGrade(){
    this->setGrade(this->grade - 1);
}

void Bureaucrat::decreaseGrade(){
    this->setGrade(this->grade + 1);
}

void Bureaucrat::setGrade(int value){
    if (value > 150)
        throw GradeTooLowException();
    else if(value < 1)
        throw GradeTooHighException();
    else 
        this->grade = value;
    
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
    return ("Grade is too high, out of interval.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return ("Grade is too low, out of interval.");
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& object){
    out << object.getName() << ", bureaucrat grade " << object.getGrade() << "." << std::endl;
    return out;
}
