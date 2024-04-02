#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain Constructor called" << std::endl;
}

Brain::~Brain() {
	std::cout << "Brain Destructor called" << std::endl;
}

Brain::Brain(const Brain &rhs) {
	std::cout << "Brain Copy Constructor called" << std::endl;
	*this = rhs;
}

Brain &Brain::operator=(const Brain &rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	for (int i = 0; i <= 100; i++)
	{
		this->_ideas[i] = rhs._ideas[i];
	}
	return *this;
}