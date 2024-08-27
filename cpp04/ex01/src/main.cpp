#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        delete j;//should not create a leak
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
        std::cout << "Basic making a sound" << std::endl;
        basic.makeSound();
        std::cout << "----------------------" << std::endl;
        std::cout << "Test virtual destructor" << std::endl;
        Cat *a = new Cat();
        Animal *b = a;
        delete b;
    }
    return 0;
}