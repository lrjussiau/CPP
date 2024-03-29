#ifndef CLAPTRAP_H
# define CLAPTRAP_H

#include <iostream>

class ClapTrap {

    protected:

        std::string		_name;
        unsigned int	_health;
        unsigned int	_energy;
        unsigned int	_attackDamage;

    public:

        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &);
        ~ClapTrap();
        ClapTrap &operator=(const ClapTrap &rhs);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif