#ifndef DIAMONDTRAP_H
# define DIAMONDTRAP_H

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {

    private:

		std::string _name;

    public:
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap &);
        ~DiamondTrap();
        DiamondTrap &operator=(const DiamondTrap &rhs);

		void	whoAmI();
};

#endif