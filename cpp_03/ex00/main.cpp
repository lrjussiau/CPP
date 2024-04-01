#include "ClapTrap.hpp"

int main( void )
{
    ClapTrap clap("Ash");

    clap.attack("Staff");
    clap.beRepaired(2);
    clap.takeDamage(9);
    clap.attack("Staff");
    clap.attack("Staff");
    clap.attack("Staff");
    clap.attack("Staff");
    clap.attack("Staff");
    clap.attack("Staff");
    clap.attack("Staff");
    clap.attack("Staff");
    clap.attack("Staff");
    clap.attack("Staff");

    return EXIT_SUCCESS;
}