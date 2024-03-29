#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int n) : _fixedPointValue (n << _fractionaryBits) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n) : _fixedPointValue (std::roundf(n * (1 << _fractionaryBits))) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &rhs) {
    std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(rhs.getRawBits());
}

Fixed &Fixed::operator=(Fixed const &rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->_fixedPointValue = rhs.getRawBits();
    return *this;
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