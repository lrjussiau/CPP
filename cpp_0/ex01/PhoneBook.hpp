
#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <cctype>
# include "Contact.hpp"

class PhoneBook {

	private:

		Contact	_contact[8];

	public:
	
		PhoneBook();
		~PhoneBook();
		void	add(void);
		void	search(void);
};

#endif