#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

    private:
        ScavTrap();

    public:
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &);
        ~ScavTrap();
        ScavTrap &operator=(const ScavTrap &rhs);

        void guardGate();
        void attack(const std::string& target);
};

#endif