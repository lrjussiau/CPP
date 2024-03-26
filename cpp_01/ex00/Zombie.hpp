#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>

class Zombie {
	private:

		std::string	name;

	public:

		Zombie();
		~Zombie();

		void	announce(void);
		Zombie*	newZombie(std::string);
		void	randomChump(std::string);
};

#endif