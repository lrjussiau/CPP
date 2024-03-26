#include "PhoneBook.hpp"

int	main(void) {
	PhoneBook	phone;
	std::string input = "";

	do {
		std::cin >> input;
		if (!input.compare("EXIT"))
			break ;
		else if (!input.compare("ADD"))
			phone.add();
		else if (!input.compare("SEARCH"))
			phone.search();
		else
			std::cout << "Not correct Input." << std::endl;
		std::cout << std::endl;
   		std::cout << "--------------USAGE---------------" << std::endl;
    	std::cout << "ADD\t: To add a contact." << std::endl;
    	std::cout << "SEARCH\t: To search for a contact." << std::endl;
    	std::cout << "EXIT\t: to quite the PhoneBook." << std::endl;
    	std::cout << "----------------------------------" << std::endl;
    	std::cout << std::endl;
	} while (1);
	std::cout << "Thanks for using Awesome PhoneBook !" << std::endl;
}