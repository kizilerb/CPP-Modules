#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
    private :
        int fixedNum;
        static const int fracBits = 8;
    public :
        Fixed();
        Fixed(const int num);
        Fixed(const float num);
        ~Fixed();
        Fixed& operator=(const Fixed& copy);
        Fixed(const Fixed& copy);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;

        //comparing operators
        bool operator<(const Fixed& other);
        bool operator>(const Fixed& other);
        bool operator>=(const Fixed& other);
        bool operator<=(const Fixed& other);
        bool operator==(const Fixed& other);
        bool operator!=(const Fixed& other);

        //arithmetic operators
        Fixed operator+(const Fixed& other);
        Fixed operator-(const Fixed& other);
        Fixed operator*(const Fixed& other);
        Fixed operator/(const Fixed& other);

        //increment operators
        Fixed operator++(int);
        Fixed& operator++();

        //decrement operators
        Fixed operator--(int);
        Fixed& operator--();

        //min max functions
        static Fixed& min(Fixed& num1, Fixed& num2);
        static const Fixed& min(const Fixed& num1, const Fixed& num2);
        static Fixed& max(Fixed& num1, Fixed& num2);
        static const Fixed& max(const Fixed& num1, const Fixed& num2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& num);

#endif