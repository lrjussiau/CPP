#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _health(10), _energy(10), _attackDamage(0) {
    std::cout << "ClapTrap " << _name << " is born!" << std::endl;
    return;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called" << std::endl;
    return;
}

ClapTrap::ClapTrap(const ClapTrap &rhs) {
    *this = rhs;
    std::cout << "ClapTrap copy constructor called" << std::endl;
    return;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->_name = rhs._name;
    this->_energy = rhs._energy;
    this->_health = rhs._health;
    this->_attackDamage = rhs._attackDamage;
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    if (_energy <= 0)
    {
        std::cout << "ClapTrap " << _name << " is out of energy!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
    _energy -= 1;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_energy <= 0)
    {
        std::cout << "ClapTrap " << _name << " is out of energy!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " takes " << amount << " damage!" << std::endl;
    _health -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_energy <= amount)
    {
        std::cout << "ClapTrap " << _name << " is out of energy!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " hit points!" << std::endl;
    _energy -= 1;
    _health += amount;
}