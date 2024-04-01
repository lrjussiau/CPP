#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed {

    public:

        Fixed(void);
        ~Fixed(void);
        Fixed(const Fixed &rhs);
        Fixed &operator=(const Fixed &rhs);

        int     getRawBits(void) const;
        void    setRawBits(int const raw);

    private:

        int               _fixedPointValue;
        const static int  _fractionaryBits = 8;
};


#endif