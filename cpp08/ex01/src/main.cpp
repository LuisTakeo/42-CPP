#include "main.hpp"


void testWithVector()
{
	std::cout << "Test 1" << std::endl;
	std::cout << "Creating Span" << std::endl;
	Span sp = Span(5);
	std::cout << "Adding numbers to Span" << std::endl;
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	try
	{
		std::cout << "Printing values of sp: ";
		sp.printValues();
		std::cout << "Shortest span of sp: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span of sp: " << sp.longestSpan() << std::endl;

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "Test 2" << std::endl;
	std::cout << "Creating Span size 10" << std::endl;
	Span sp2 = Span(10);
	std::cout << "Creating a vector" << std::endl;
	std::vector<int> v;

	try
	{
		std::cout << "Trying to check longest span of empty Span" << std::endl;
		sp2.longestSpan();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "Trying to check shortest span of empty Span" << std::endl;
		sp2.shortestSpan();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "Adding values to vector" << std::endl;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
	try
	{
		std::cout << "Filling Span with vector values" << std::endl;
		sp2.fillVector(v.begin(), v.end());
		std::cout << "Printing values of sp2: ";
		sp2.printValues();
		std::cout << "Shortest span of sp2: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span of sp2: " << sp2.longestSpan() << std::endl;

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "Trying to add more values than the size of the Span" << std::endl;
		sp2.fillVector(v.begin(), v.end());
		std::cout << "Printing values of sp2: ";
		sp2.printValues();
		std::cout << "Shortest span of sp2: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span of sp2: " << sp2.longestSpan() << std::endl;
		std::cout << "Adding more values to vector" << std::endl;
		sp2.fillVector(v.begin(), v.end());
		std::cout << "Printing values of sp2: ";
		sp2.printValues();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}


void testWithArray()
{
	std::cout << "Test 3" << std::endl;
	std::cout << "Creating Span with array" << std::endl;
	int arr[] = {10, 20, 30, 40, 50};
    size_t arrSize = sizeof(arr) / sizeof(arr[0]);
	Span sp3 = Span(5);
	try
	{
		std::cout << "Fill vector with array values" << std::endl;
    	sp3.fillVector(arr, arr + arrSize);
		std::cout << "Printing values of sp3: ";
		sp3.printValues();
		std::cout << "Shortest span of sp3: " << sp3.shortestSpan() << std::endl;
		std::cout << "Longest span of sp3: " << sp3.longestSpan() << std::endl;


	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	testWith10000value()
{
	std::cout << "Test 4" << std::endl;
	std::cout << "Creating Span with 10000 values" << std::endl;
	Span sp4 = Span(10000);
	std::vector<int> v;
	for (int i = 0; i < 10000; i++)
		v.push_back(i + (i % 10000 ? i * 10 : i * 10000));
	std::cout << "Shuffling vector" << std::endl;
	std::random_shuffle(v.begin(), v.end());
	try
	{
		std::cout << "Filling Span with vector values" << std::endl;
		sp4.fillVector(v.begin(), v.end());
		std::cout << "Printing values of sp4: ";
		sp4.printValues();
		std::cout << "Shortest span of sp4: " << sp4.shortestSpan() << std::endl;
		std::cout << "Longest span of sp4: " << sp4.longestSpan() << std::endl;
		std::cout << "Adding one more value to the Span" << std::endl;
		sp4.addNumber(10000);
		std::cout << "Printing values of sp4: ";
		sp4.printValues();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	testWithVector();
	std::cout << "--------------------------------" << std::endl;
	std::cout << "--------------------------------" << std::endl;
	testWithArray();
	std::cout << "--------------------------------" << std::endl;
	std::cout << "--------------------------------" << std::endl;
	testWith10000value();
	std::cout << "--------------------------------" << std::endl;
	std::cout << "--------------------------------" << std::endl;


    // std::cout << std::endl;
	return 0;
}