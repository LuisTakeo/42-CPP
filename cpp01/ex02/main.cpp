#include <iostream>

int main()
{
    std::string name = "HI THIS IS BRAIN";
    std::string *nameptr = &name;
    std::string &nameref = name;

    std::cout << "Memory address:" << std::endl;
    std::cout << "name: " << &name << std::endl;
    std::cout << "nameptr: " << nameptr << std::endl;
    std::cout << "nameref: " << &nameref << std::endl;

    std::cout << "Values -> name: " << name << std::endl;
    std::cout << "Memory address -> nameptr: " << *nameptr << std::endl;
    std::cout << "Memory address -> nameref: " << nameref << std::endl;
}