#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound(); //dog sound
        meta->makeSound(); // generic sound

        const Animal *copy = meta;

        copy->makeSound();

        delete meta;
        delete j;
        delete i;
    }
    {
        // const WrongAnimal* meta = new Animal(); // << error on compilation
        // const Cat cat = new Dog(); // << error on compilation
        const WrongAnimal* j = new WrongAnimal();
        const WrongAnimal* i = new WrongCat();

        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound(); //dog sound
        delete j;
        delete i;
    }

    {
        Animal* meta = new Animal();
        Animal* j = new Dog();
        Cat* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound(); //dog sound
        meta->makeSound(); // generic sound

        Animal *newAnimal = new Animal(*j);
        Cat     cat = *i;

        cat.makeSound();
        newAnimal->makeSound();

        delete meta;
        delete j;
        delete i;
        delete newAnimal;
    }
    return 0;
}