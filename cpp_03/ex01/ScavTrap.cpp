#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
    this->_health = 100;
    this->_energy = 50;
    this->_attackDamage = 20;

    std::cout << "< ScavTrap > - " << this->_name << " constructed." << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called" << std::endl;
    return;
}

ScavTrap::ScavTrap(const ScavTrap &rhs) : ClapTrap(rhs) {
    *this = rhs;
    std::cout << "ScavTrap copy constructor called" << std::endl;
    return;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->_name = rhs._name;
    this->_energy = rhs._energy;
    this->_health = rhs._health;
    this->_attackDamage = rhs._attackDamage;
    return *this;
}

void    ScavTrap::guardGate() {
    std::cout << "< ScavTrap > - " << this->_name << " is now in Gate keeper mode." << std::endl;
}
