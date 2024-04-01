#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

    private:
        ScavTrap();

    public:
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &);
        ~ScavTrap();
        ScavTrap &operator=(const ScavTrap &rhs);

        void guardGate();
};

#endif