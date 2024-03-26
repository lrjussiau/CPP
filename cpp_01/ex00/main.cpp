#include "Zombie.hpp"

int main(void) {

	Zombie zomb("Lol");
	zomb.announce();

	randomChump("Foo");

	Zombie *zombi = newZombie("OKAAY");
	zombi->announce();
	delete zombi;
}