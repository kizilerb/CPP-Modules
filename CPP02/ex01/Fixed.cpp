#include "Fixed.hpp"

Fixed::Fixed(){
    this->fixedNum = 0;
    std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed(const int num){
    this->fixedNum = num * pow(2, fracBits);
    std::cout << "Int constructor is called." << std::endl;
}

Fixed::Fixed(const float num){
    this->fixedNum = roundf(num * pow(2, fracBits));
    std::cout << "Float constructor is called." << std::endl;
}

float Fixed::toFloat( void ) const{
    return (float)this->fixedNum / pow(2,fracBits); 
}

int Fixed::toInt( void ) const{
    return this->fixedNum / pow(2,fracBits);
}

Fixed& Fixed::operator=(const Fixed& copy){
    std::cout << "Copy assignment operator called." << std::endl;
    this->setRawBits(copy.getRawBits());
    return *this;
}

Fixed::Fixed(const Fixed& copy){
    std::cout << "Copy constructor called." << std::endl;
    *this = copy;
}

Fixed::~Fixed(){
    std::cout << "Destructor called." << std::endl;
}

int Fixed::getRawBits( void ) const{
    std::cout << "getRawBits member function called." << std::endl;
    return this->fixedNum;
}

void Fixed::setRawBits(int const raw){
    std::cout << "setRawBits member function called." << std::endl;
    this->fixedNum = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& num){
    out << num.toFloat();
    return out;
}