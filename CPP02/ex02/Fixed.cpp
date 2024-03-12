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


//comparing operators
bool Fixed::operator<(const Fixed& other){
    return (this->fixedNum < other.fixedNum ? 1 : 0);
}

bool Fixed::operator>(const Fixed& other){
    return (this->fixedNum > other.fixedNum ? 1 : 0);
}

bool Fixed::operator>=(const Fixed& other){
    return (this->fixedNum >= other.fixedNum ? 1 : 0);
}

bool Fixed::operator<=(const Fixed& other){
    return (this->fixedNum <= other.fixedNum ? 1 : 0);
}

bool Fixed::operator==(const Fixed& other){
    return (this->fixedNum == other.fixedNum ? 1 : 0);
}

bool Fixed::operator!=(const Fixed& other){
    return (this->fixedNum != other.fixedNum ? 1 : 0);
}


//arithmetic operators
Fixed Fixed::operator+(const Fixed& other){
    Fixed ret;
    ret.fixedNum = this->fixedNum + other.fixedNum;
    return ret;
}

Fixed Fixed::operator-(const Fixed& other){
    Fixed ret;
    ret.fixedNum = this->fixedNum - other.fixedNum;
    return ret;
}

Fixed Fixed::operator*(const Fixed& other){
    Fixed ret;
    ret.fixedNum = this->fixedNum * other.fixedNum;
    return ret;
}

Fixed Fixed::operator/(const Fixed& other){
    Fixed ret;
    ret.fixedNum = this->fixedNum / other.fixedNum;
    return ret;
}


//increment operators
Fixed Fixed::operator++(int){
    Fixed ret = *this;
    (this->fixedNum)++;
    return ret;
}

Fixed& Fixed::operator++(){
    (this->fixedNum)++;
    return *this;
}


//decrement operators
Fixed Fixed::operator--(int){
    Fixed ret = *this;
    (this->fixedNum)--;
    return ret;
}

Fixed& Fixed::operator--(){
    (this->fixedNum)--;
    return *this;
}


//Min Max functions
