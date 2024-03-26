#include <iostream>

void convertToUpperCase(std::string &str) {
    for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
        char &c = *it;
        c = std::toupper(c);
    }
}

int	main(int argc, char **argv) 
{
	std::string str;
	int 		i;

	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		do {
			str = argv[i];
			convertToUpperCase(str);
			std::cout << str;
			i++;
		} while (argv[i]);
	}
	std::cout << std::endl;
}