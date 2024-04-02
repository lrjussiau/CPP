#include "Animal.hpp"

Animal::Animal(void) {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &rhs) {
	*this = rhs;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
    this->_type = rhs._type;
    return *this;
}

void	Animal::makeSound(void) const {
	std::cout << "Sound of Animal" << std::endl;
}

std::string Animal::getType(void) const{
	return (this->_type);
}