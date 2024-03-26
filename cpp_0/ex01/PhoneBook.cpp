#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
	std::cout << std::endl;
    std::cout << "📞 Welcome to Your Awesome PhoneBook 📖" << std::endl;
    std::cout << std::endl;
    std::cout << "--------------USAGE---------------" << std::endl;
    std::cout << "ADD\t: To add a contact." << std::endl;
    std::cout << "SEARCH\t: To search for a contact." << std::endl;
    std::cout << "EXIT\t: to quite the PhoneBook." << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << std::endl;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::add(void) {
	static int i;

	this->_contact[i % 8].add_contact(i % 8);
	i++;
}

void	PhoneBook::search(void) {
	std::string	index;
	int j = 0;

	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "Firstname" << "|";
	std::cout << std::setw(10) << "Lastname" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (!this->_contact[i].display_contact()) {
			std::cout << std::setw(10) << i << "|";
			std::cout << std::setw(10) << "" << "|";
			std::cout << std::setw(10) << "" << "|";
			std::cout << std::setw(10) << std::endl;
		}
	}
	do {
		std::cout << std::endl << "Please enter the index of the contact : ";
		std::cin >> index;
		if (isdigit(index[0]) && index.length() == 1)
		{
			j = std::stoi(index);
			if (j >= 0 && j < 8)
				break ;
		}
		else
			std::cout << "Wrong index. Must be beetween 0 and 7." << std::endl;
	} while (1);
	this->_contact[j].search_contact();
}