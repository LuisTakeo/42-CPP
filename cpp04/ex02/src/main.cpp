#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    {
        const AAnimal* j = new Dog();
        const AAnimal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound(); //dog sound
        delete j;
        delete i;
    }
    // {
    //     std::cout << "----------------------" << std::endl;
    //     std::cout << "Test basic" << std::endl;
    //     Dog basic;
    //     {
    //         Dog temp = basic;
    //         Dog anotherDog(temp);
    //     }
    //     basic.makeSound();
    //     std::cout << "----------------------" << std::endl;
    //     std::cout << "Test virtual destructor" << std::endl;
        Cat *a = new Cat();
        AAnimal *b = a;
        delete b;
    // }
    return 0;
}