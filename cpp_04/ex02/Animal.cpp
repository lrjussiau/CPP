#include "Animal.hpp"

AAnimal::AAnimal(void) {
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type) {
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &rhs) {
	*this = rhs;
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
    this->_type = rhs._type;
    return *this;
}

void	AAnimal::makeSound(void) const {
	std::cout << "Sound of AAnimal" << std::endl;
}

std::string AAnimal::getType(void) const{
	return (this->_type);
}