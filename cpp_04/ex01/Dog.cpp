#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog constructor called" << std::endl;
	Animal::_type = "Dog";
	this->_brain = new Brain();

}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

Dog::Dog(const Dog &rhs) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = rhs;
}

Dog &Dog::operator=(const Dog &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
    this->_type = rhs._type;
	this->_brain = new Brain();
    return *this;
}

void	Dog::makeSound(void) const {
	std::cout << "Wouf" << std::endl;
}