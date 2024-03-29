#include "ScavTrap.hpp"

int main( void )
{
    ClapTrap clap("Ash");
    ScavTrap Serena("Serena");

    clap.attack("Staff");
    Serena.guardGate();
    Serena.attack("Lol");


    return EXIT_SUCCESS;
}