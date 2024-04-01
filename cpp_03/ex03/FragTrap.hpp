#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

    private:
        FragTrap();

    public:
        FragTrap(std::string name);
        FragTrap(const FragTrap &);
        ~FragTrap();
        FragTrap &operator=(const FragTrap &rhs);

		void	highFivesGuys(void);
};

#endif