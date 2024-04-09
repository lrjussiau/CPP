#include "ScalarConverter.hpp"

int main (int argc, char **argv) {
	
	if (argc != 2) {
		std::cout << "You have to input a number : ./convert number" << std::endl;
		return 0;
	}
	std::string number = argv[1];
	if (!number.empty())
		ScalarConverter::convert(argv[1]);
	else
		std::cout << "You have to input a number : ./convert number" << std::endl;
	return 0;
}