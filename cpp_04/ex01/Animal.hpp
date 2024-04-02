#ifndef ANIMAL_H
# define ANIMAL_H

#include <iostream>

class Animal {

	protected:
		std::string _type;
	public:
		Animal(void);
		Animal(std::string type);
		virtual ~Animal();
		Animal(const Animal &);
		Animal &operator=(const Animal &rhs);

		virtual void	makeSound(void) const;
		std::string		getType(void) const;
};

#endif