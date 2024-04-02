#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &rhs) {
	*this = rhs;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
    this->_type = rhs._type;
    return *this;
}

void	WrongAnimal::makeSound(void) const {
	std::cout << "Sound of WrongAnimal" << std::endl;
}

std::string WrongAnimal::getType(void) const{
	return (this->_type);
}