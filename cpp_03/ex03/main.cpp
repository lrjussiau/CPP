#include "DiamondTrap.hpp"

int main( void )
{
    ClapTrap clap("Ash");
    ScavTrap Serena("Serena");
    FragTrap boy("Fragou");
    DiamondTrap okayy("Didi");

    clap.attack("Staff");
    Serena.guardGate();
    Serena.attack("Lol");
    boy.highFivesGuys();
    boy.attack("DontKnow");
    okayy.whoAmI();
    okayy.attack("Le mechant");


    return EXIT_SUCCESS;
}