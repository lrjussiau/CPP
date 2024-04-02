#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat constructor called" << std::endl;
	AAnimal::_type = "Cat";
	this->_brain = new Brain();
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

Cat::Cat(const Cat &rhs) {
	*this = rhs;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
    this->_type = rhs._type;
	this->_brain = new Brain();
    return *this;
}

void	Cat::makeSound(void) const {
	std::cout << "Miaou" << std::endl;
}