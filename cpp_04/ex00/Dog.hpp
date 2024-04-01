#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"

class Dog : public Animal {

	private:

	public:
		Dog();
		~Dog();
		Dog(const Dog &);
		Dog &operator=(const Dog &rhs);

		void makeSound(void) const;
};

#endif