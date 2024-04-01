#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{	
	this->_health = 100;
    this->_energy = 100;
    this->_attackDamage = 30;

    std::cout << "FragTrap " << this->_name << " constructed." << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called" << std::endl;
    return;
}

FragTrap::FragTrap(const FragTrap &rhs) : ClapTrap(rhs) {
    *this = rhs;
    std::cout << "FragTrap copy constructor called" << std::endl;
    return;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->_name = rhs._name;
    this->_energy = rhs._energy;
    this->_health = rhs._health;
    this->_attackDamage = rhs._attackDamage;
    return *this;
}

void    FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << this->_name << " try to high fives !" << std::endl;
}