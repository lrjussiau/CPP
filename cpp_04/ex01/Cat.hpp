#ifndef CAT_H
# define CAT_H

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {

	private:
		Brain* _brain;

	public:
		Cat();
		~Cat();
		Cat(const Cat &);
		Cat &operator=(const Cat &rhs);

		void makeSound(void) const;
};

#endif