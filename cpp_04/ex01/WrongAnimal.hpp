#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

#include <iostream>

class WrongAnimal {

	protected:
		std::string _type;
	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		virtual ~WrongAnimal();
		WrongAnimal(const WrongAnimal &);
		WrongAnimal &operator=(const WrongAnimal &rhs);

		void	makeSound(void) const;
		std::string		getType(void) const;
};

#endif