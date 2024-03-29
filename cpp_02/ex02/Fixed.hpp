#ifndef FIXED_H
# define FIXED_H

#include <iostream>
#include <cmath>

class Fixed {

    public:

        Fixed(void);
        Fixed(const int n);
        Fixed(const float n);
        ~Fixed(void);
        Fixed(const Fixed &rhs);

        Fixed &operator=(const Fixed &rhs);
        Fixed &operator+(const Fixed &rhs);
        Fixed &operator-(const Fixed &rhs);
        Fixed &operator*(const Fixed &rhs);
        Fixed &operator/(const Fixed &rhs);
        Fixed operator++(const int);
        Fixed &operator++(void);
        Fixed operator--(const int);
        Fixed &operator--(void);

        bool operator==(const Fixed &rhs);
        bool operator!=(const Fixed &rhs);
        bool operator>=(const Fixed &rhs);
        bool operator<=(const Fixed &rhs);
        bool operator>(const Fixed &rhs);
        bool operator<(const Fixed &rhs);

        static Fixed& min(Fixed &a, Fixed &b);
        static const Fixed& min(const Fixed &a, const Fixed &b);
        static Fixed& max(Fixed &a, Fixed &b);
        static const Fixed& max(const Fixed &a, const Fixed &b);

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        int     toInt(void) const;
        float   toFloat(void) const;

    private:

        int               _fixedPointValue;
        const static int  _fractionaryBits = 8;
};

std::ostream &  operator<<(std::ostream & o, Fixed const & i);
#endif