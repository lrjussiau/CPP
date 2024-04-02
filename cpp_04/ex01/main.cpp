#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main( void )
{

	Dog basic;
	{
		std::cout << std::endl;
		Dog tmp = basic;
		std::cout << std::endl;
	}	
	std::cout << std::endl;

    const Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };
    for ( int i = 0; i < 4; i++ ) {
        delete animals[i];
		std::cout << std::endl;
    }

    return 0;
}