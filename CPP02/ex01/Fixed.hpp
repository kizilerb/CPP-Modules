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
};

std::ostream& operator<<(std::ostream& os, const Fixed& num);

#endif