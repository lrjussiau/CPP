#include "Harl.hpp"

int main (int argc, char **argv) {
	Harl		harl;

	if (argc == 2)
		harl.complain(argv[1]);
	else
		std::cout << "Error Program should have 1 argument. (WARNING,DEBUG,ERROR,INFO)" << std::endl;
}