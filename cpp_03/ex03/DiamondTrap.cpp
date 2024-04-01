#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( std::string name ) : ClapTrap(name), FragTrap(name), ScavTrap(name)
{
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";

    FragTrap::_health = 100;
    ScavTrap::_energy = 50;
    FragTrap::_attackDamage = 30;

    std::cout << "DiamondTrap " << this->_name << " constructed." << std::endl;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called" << std::endl;
    return;
}

DiamondTrap::DiamondTrap(const DiamondTrap &rhs) : ClapTrap(rhs), FragTrap(rhs), ScavTrap(rhs) {
    *this = rhs;
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    return;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->_name = rhs._name;
    this->_energy = rhs._energy;
    this->_health = rhs._health;
    this->_attackDamage = rhs._attackDamage;
    return *this;
}

void	DiamondTrap::whoAmI() {
	std::cout << "I am " << this->_name << " and my Clap Trap name is " << this->ClapTrap::_name << std::endl;
}
