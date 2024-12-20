#include "whatever.hpp"



void evaluation_tests(void)
{
	Awesome a(2), b(4);

    std::cout << a << " " << b << std::endl;
    std::cout << "swap(a, b)" << std::endl;
    swap(a, b);
    std::cout << "a = " << a << " b = " << b << std::endl;
    std::cout << "max(a, b)" << max(a, b) << std::endl;
    std::cout << "min(a, b)"  << min(a, b) << std::endl;
}

void    myTests()
{
    std::cout << "Test 1: int" << std::endl;
    int a = 2;
    int b = 3;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "swap(a, b)" << std::endl;
    swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << min(a, b) << std::endl;
    std::cout << "max(a, b) = " << max(a, b) << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Test 2: char " << std::endl;
    char c = 'a';
    char d = 'b';
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "swap(c, d)" << std::endl;
    swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << min(c, d) << std::endl;
    std::cout << "max(c, d) = " << max(c, d) << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Test 3: double " << std::endl;
    double e = 2.5;
    double f = 3.5;
    std::cout << "e = " << e << ", f = " << f << std::endl;
    std::cout << "swap(e, f)" << std::endl;
    swap(e, f);
    std::cout << "e = " << e << ", f = " << f << std::endl;
    std::cout << "min(e, f) = " << min(e, f) << std::endl;
    std::cout << "max(e, f) = " << max(e, f) << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Test 4: string " << std::endl;
    std::string g = "chaine1";
    std::string h = "chaine2";
    std::cout << "g = " << g << ", h = " << h << std::endl;
    std::cout << "swap(g, h)" << std::endl;
    swap(g, h);
    std::cout << "g = " << g << ", h = " << h << std::endl;
    std::cout << "min(g, h) = " << ::min(g, h) << std::endl;
    std::cout << "max(g, h) = " << ::max(g, h) << std::endl;
    std::cout << "--------------------------------" << std::endl;
}


int main()
{
    std::cout << "Evaluation tests" << std::endl;
    evaluation_tests();
    std::cout << "================================" << std::endl;
    myTests();
    return 0;
}