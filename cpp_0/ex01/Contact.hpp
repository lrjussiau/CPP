
#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <iomanip>

class Contact {

	private:

		int	_index;
		std::string	_FirstName;
		std::string	_LastName;
		std::string	_Nickname;
		std::string _PhoneNumber;
		std::string _Secret;

		std::string _get_input(std::string str) const;
		std::string	_get_str(std::string str) const;

	public:

		Contact();
		~Contact();

		void	add_contact(int index);
		void	search_contact(void) const;
		bool	display_contact(void) const;

};

#endif