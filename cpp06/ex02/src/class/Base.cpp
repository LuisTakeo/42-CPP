#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base *Base::generate(void)
{
	static int i = 0;
	if (i == 0)
	{
		srand(time(NULL));
		i++;
	}

	int random = rand() % 3;
	switch (random)
	{
		case 0:
			return new A();
			break;
		case 1:
			return new B();
			break;
		case 2:
			return new C();
			break;
		default:
			break;
	}
	return NULL;
}

void Base::identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Class A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Class B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Class C" << std::endl;
}

void Base::identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "Class A" << std::endl;
	}
	catch (std::exception &e)
	{}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "Class B" << std::endl;
	}
	catch (std::exception &e)
	{}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "Class C" << std::endl;
	}
	catch (std::exception &e)
	{}
}