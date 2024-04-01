#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
const WrongAnimal* Wani = new WrongAnimal();
const WrongAnimal* k = new WrongCat();

std::cout << "Dog.getType : " << j->getType() << " " << std::endl;
std::cout << "Cat.getType : " << i->getType() << " " << std::endl;
std::cout << "WrongCat.getType : " << k->getType() << " " << std::endl;

std::cout << "Cat sound :" <<std::endl;
i->makeSound();
std::cout << "Dog sound :" <<std::endl;
j->makeSound();
std::cout << "Animal sound :" <<std::endl;
meta->makeSound();
std::cout << std::endl;
std::cout << "With no Virtual makeSound" << std::endl;
std::cout << "Animal sound :" <<std::endl;
Wani->makeSound();
std::cout << "Cat sound :" <<std::endl;
k->makeSound();
std::cout << std::endl;

delete j;
delete i;
delete meta;
delete k;
delete Wani;

return 0;
}