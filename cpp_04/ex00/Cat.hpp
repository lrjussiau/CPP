#ifndef CAT_H
# define CAT_H

#include "Animal.hpp"

class Cat : public Animal {

	private:

	public:
		Cat();
		~Cat();
		Cat(const Cat &);
		Cat &operator=(const Cat &rhs);

		void makeSound(void) const;
};

#endif