#ifndef DOG_H
# define DOG_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {

	private:
		Brain* _brain;

	public:
		Dog();
		virtual ~Dog();
		Dog(const Dog &);
		Dog &operator=(const Dog &rhs);

		void makeSound(void) const;
};

#endif