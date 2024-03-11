#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
    private :
        int fixedNum;
        static const int bits = 8;
    public :
        Fixed();
        Fixed& operator=(const Fixed& copy);
        Fixed(const Fixed& copy);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif