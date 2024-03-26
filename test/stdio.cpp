#include <iostream>

int	main(void) {

	char	buff[512];

	std::cout << "Hello World !" << std::endl;
	std::cout << "Ok entre quelque chose ";
	std::cin >> buff;
	std::cout << "tu as entrer " << buff << std::endl;
}