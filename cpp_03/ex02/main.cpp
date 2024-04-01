#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
    ClapTrap clap("Ash");
    ScavTrap Serena("Serena");
    FragTrap boy("Fragou");

    clap.attack("Staff");
    Serena.guardGate();
    Serena.attack("Lol");
    boy.highFivesGuys();
    boy.attack("DontKnow");


    return EXIT_SUCCESS;
}