#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat constructor called" << std::endl;
	Animal::_type = "Cat";
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &rhs) {
	*this = rhs;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
    this->_type = rhs._type;
    return *this;
}

void	Cat::makeSound(void) const {
	std::cout << "Miaou" << std::endl;
}