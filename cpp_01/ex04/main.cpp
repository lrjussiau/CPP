#include <iostream>
#include <fstream>
#include <sstream>

void replaceInLine(std::string& line, const std::string& s1, const std::string& s2) {
    size_t pos = line.find(s1);
    while (pos != std::string::npos) {
        line.erase(pos, s1.length());
        line.insert(pos, s2);
        pos = line.find(s1, pos + s2.length());
    }
}

int main (int argc, char **argv) {
	if (argc != 4)
	{
		std::cerr << "Error : Must have 3 arguments";
		return 1;
	}
	std::ifstream file(argv[1]);
	if (!file.is_open()) {
		std::cerr << "Failed to open " << argv[1] << " file." << std::endl;
		return 1;
	}

	std::stringstream	modifiedLines;
	std::string 		line;

	while (std::getline(file, line)) {
		replaceInLine(line, argv[2], argv[3]);
        modifiedLines << line << std::endl;
    }

	file.close();

	std::ofstream outFile(argv[1]);
    if (!outFile.is_open()) {
        std::cerr << "Error opening file for writing." << std::endl;
        return 1;
    }

    outFile << modifiedLines.str();

    outFile.close();
}