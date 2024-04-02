#ifndef ANIMAL_H
# define ANIMAL_H

#include <iostream>

class AAnimal {

	protected:
		std::string _type;
	public:
		AAnimal(void);
		AAnimal(std::string type);
		virtual ~AAnimal();
		AAnimal(const AAnimal &);
		AAnimal &operator=(const AAnimal &rhs);

		virtual void	makeSound(void) const = 0;
		std::string		getType(void) const;
};

#endif