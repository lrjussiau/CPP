#include "Sample.hpp"

Sample::Sample (void) {
	std::cout << "Constructor called" << std::endl;
	this->i = 42;
	std::cout << this->i << std::endl;
	return;
}

Sample::~Sample (void) {
	std::cout << "Destructor Called" << std::endl;
	return;
}

void	Sample::func (void) {
	std::cout << "Func Called" << std::endl;
	return;
}