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