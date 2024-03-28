#include "Harl.hpp"

int main (void) {
	std::string	level;
	Harl		harl;

	std::cout << std::endl << "Enter a level : ";
	std::cin >> level;
	std::cout << std::endl;

	harl.complain(level);
}