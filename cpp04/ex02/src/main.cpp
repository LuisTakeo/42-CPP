#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    {
        std::cout << "Tests pdf: " << std::endl;
        const AAnimal* j = new Dog();
        const AAnimal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound(); //dog sound
        delete j;
        delete i;

        // AAnimal animal;
    }

    Cat *a = new Cat();
    AAnimal *b = a;
    delete b;
    return 0;
}