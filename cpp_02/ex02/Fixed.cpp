#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointValue(0) {
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void) {
    // std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int n) : _fixedPointValue (n << _fractionaryBits) {
    // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n) : _fixedPointValue (std::roundf(n * (1 << _fractionaryBits))) {
    // std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &rhs) {
    this->setRawBits(rhs.getRawBits());
}

Fixed &Fixed::operator=(Fixed const &rhs) {
    this->_fixedPointValue = rhs.getRawBits();
    return *this;
}

Fixed &Fixed::operator+(Fixed const &rhs) {
    this->_fixedPointValue += rhs.toFloat();
    return *this;
}

Fixed &Fixed::operator-(Fixed const &rhs) {
    this->_fixedPointValue -= rhs.toFloat();
    return *this;
}

Fixed &Fixed::operator*(Fixed const &rhs) {
    this->_fixedPointValue *= rhs.toFloat();
    return *this;
}

Fixed &Fixed::operator/(Fixed const &rhs) {
    this->_fixedPointValue /= rhs.toFloat();
    return *this;
}

bool Fixed::operator==(const Fixed &rhs) {
    if (this->_fixedPointValue == rhs.getRawBits())
        return true;
    return false;
}

bool Fixed::operator!=(const Fixed &rhs) {
    if (this->_fixedPointValue != rhs.getRawBits())
        return true;
    return false;
}

bool Fixed::operator<=(const Fixed &rhs) {
    if (this->_fixedPointValue <= rhs.getRawBits())
        return true;
    return false;
}

bool Fixed::operator>=(const Fixed &rhs) {
    if (this->_fixedPointValue >= rhs.getRawBits())
        return true;
    return false;
}

bool Fixed::operator<(const Fixed &rhs) {
    if (this->_fixedPointValue < rhs.getRawBits())
        return true;
    return false;
}

bool Fixed::operator>(const Fixed &rhs) {
    if (this->_fixedPointValue > rhs.getRawBits())
        return true;
    return false;
}

Fixed &Fixed::operator++(void) {
    this->_fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(const int) {
    Fixed temp(*this);
    temp._fixedPointValue = this->_fixedPointValue++;
    return temp;
}

Fixed &Fixed::operator--(void) {
    this->_fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(const int) {
    Fixed temp(*this);
    temp._fixedPointValue = this->_fixedPointValue--;
    return temp;
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b) {
    if (a.getRawBits() < b.getRawBits())
        return a;
    return b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    if (a.getRawBits() < b.getRawBits())
        return a;
    return b;
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b) {
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    if (a.getRawBits() > b.getRawBits())
        return a;
    return b;
}


int Fixed::getRawBits(void) const {
    return (this->_fixedPointValue);
}

void Fixed::setRawBits(const int raw) {
    this->_fixedPointValue = raw;
}

int Fixed::toInt(void) const {
    return (this->_fixedPointValue >> _fractionaryBits);
}

float   Fixed::toFloat(void) const {
    return static_cast<float> (this->_fixedPointValue) / (1 << _fractionaryBits);
}

std::ostream &  operator<<(std::ostream & o, Fixed const & i) {
    o << i.toFloat();
    return (o);
}