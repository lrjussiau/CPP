#ifndef WRONGCAT_H
# define WRONGCAT_H

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

	private:

	public:
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat &);
		WrongCat &operator=(const WrongCat &rhs);

		void makeSound(void) const;
};

#endif