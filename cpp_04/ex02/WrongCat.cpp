#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "WrongCat constructor called" << std::endl;
	WrongAnimal::_type = "WrongCat";
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &rhs) {
	*this = rhs;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
    this->_type = rhs._type;
    return *this;
}

void	WrongCat::makeSound(void) const {
	std::cout << "Miaou" << std::endl;
}