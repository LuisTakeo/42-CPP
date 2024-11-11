#include "iter.hpp"

void evaluation_tests()
{
    int             size = 5;
    int             tab[5] = {0, 1, 2, 3, 4};
    float           tabF[5] = {0.0f, 1.1f, 2.2f, 3.3f, 4.4f};
    std::string     tabS[5] = {"zero", "one", "two", "three", "four"};

    std::cout << "Test 1: print int" << std::endl;
    std::cout << "Calling: iter(tab, size, printRandomColor);" << std::endl;
    iter(tab, size, printRandomColor);
    std::cout << "Test 2: print string" << std::endl;
    std::cout << "Calling: iter(tabS, size, printRandomColor);" << std::endl;
    iter(tabS, size, printRandomColor);
    std::cout << "Test 3: Increment int " << std::endl;
    std::cout << "Calling: iter(tab, size, increment);" << std::endl;
    iter(tab, size, increment);
    std::cout << "Calling: iter(tab, size, printRandomColor);" << std::endl;
    iter(tab, size, printRandomColor);
    std::cout << "Test 4: Increment float " << std::endl;
    std::cout << "Calling: iter(tabF, size, increment);" << std::endl;
    iter(tabF, size, increment);
    std::cout << "Calling: iter(tabF, size, printRandomColor);" << std::endl;
    iter(tabF, size, printRandomColor);

}

int main()
{
    std::cout << "Evaluation tests" << std::endl;
    evaluation_tests();
    std::cout << "================================" << std::endl;
    // myTests();
    return 0;
}