#include <iostream>
#include <fstream>

int main (int argc, char **argv) {
	if (argc != 4)
	{
		std::cerr << "Error : Must have 3 arguments";
		return 1;
	}
	std::ifstream file(argv[1]);

	if (!file.is_open()) {
		std::cerr << "Failed to open " << argv[1] << " file." << std::endl;
	}


}