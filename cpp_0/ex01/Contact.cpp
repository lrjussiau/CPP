#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string Contact::_get_input(std::string str) const {

	std::string input = "";
	bool		valid = false;

	do {
		std::cout << str << std::endl;
		std::cin >> input;
		if (!input.empty())
			valid = true;
		else
			std::cout << "Invalid Input. Try again." << std::endl;
	} while (!valid);
	return (input);
}

std::string Contact::_get_str(std::string str) const {
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	Contact::add_contact(int index) {
	this->_index = index;
	this->_FirstName = this->_get_input("Enter your First Name : ");
	this->_LastName = this->_get_input("Enter your Last Name : ");
	this->_Nickname = this->_get_input("Enter your Nickname : ");
	this->_PhoneNumber = this->_get_input("Enter your Phone Number : ");
	this->_Secret = this->_get_input("Enter your Darkest Secret : ");
}

bool	Contact::display_contact(void) const {
	if (this->_FirstName.empty() || this->_LastName.empty() || this->_Nickname.empty())
        return (false);
	std::cout << std::setw(10) << this->_index << "|";
	std::cout << std::setw(10) << this->_get_str(this->_FirstName) << "|";
	std::cout << std::setw(10) << this->_get_str(this->_LastName) << "|";
	std::cout << std::setw(10) << this->_get_str(this->_Nickname) << std::endl;
	return (true);
}

void	Contact::search_contact(void) const {
	std::cout << "First name : " << this->_FirstName << std::endl;
	std::cout << "Last name : " << this->_LastName << std::endl;
	std::cout << "Nickname : " << this->_Nickname << std::endl;
	std::cout << "Phone number : " << this->_PhoneNumber << std::endl;
	std::cout << "Darkest Secret : " << this->_Secret << std::endl;
}