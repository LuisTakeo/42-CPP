#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

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
        std::cout << "----------------------" << std::endl;
        std::cout << "Test basic" << std::endl;
        Dog basic;
        {
            Dog temp = basic;
            Dog anotherDog(temp);
        }
        basic.makeSound();
        std::cout << "----------------------" << std::endl;
        std::cout << "Test virtual destructor" << std::endl;
        Cat *a = new Cat();
        Animal *b = a;
        delete b;
    }
    return 0;
}