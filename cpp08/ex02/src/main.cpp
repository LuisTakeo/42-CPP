#include "main.hpp"

void	testComparisonOtherList()
{
	std::cout << COLOR_GREEN << "Comparison with list" << COLOR_RESET << std::endl;
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(13);
	mstack.push_back(31);
	mstack.push_back(42);
	mstack.push_back(21);
	std::cout << "Showing all elements" << std::endl;
	printContainer(mstack);
	std::cout << "Top: " << mstack.back() << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;
	std::cout << "Popping last element" << std::endl;
	mstack.pop_back();
	std::cout << "Should be 42: " << mstack.back() << std::endl;
	std::cout << "Showing all elements" << std::endl;
	printContainer(mstack);

	std::cout << "Testing iterators" << std::endl;
	std::list<int>::iterator itBegin = mstack.begin();
	std::list<int>::iterator itEnd = mstack.end();
	std::cout << "While itBegin != itEnd" << std::endl;
	while (itBegin != itEnd)
	{
		std::cout << *itBegin << " ";
		itBegin++;
	}
	std::cout << std::endl;
	itBegin = mstack.begin();
	std::cout << "While itEnd != itBegin" << std::endl;
	while (itEnd != itBegin)
	{
		itEnd--;
		std::cout << *itEnd << " ";
	}
	std::cout << std::endl;
	std::cout << "Finished testing iterators" << std::endl;
}

void	testsMutantStack()
{
	std::cout << COLOR_GREEN << "Tests MutantStack" << COLOR_RESET << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(13);
	mstack.push(31);
	mstack.push(42);
	mstack.push(21);
	std::cout << "Showing all elements" << std::endl;
	printContainer(mstack);
	std::cout << "Last: " << mstack.top() << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;
	std::cout << "Popping last element" << std::endl;
	mstack.pop();
	std::cout << "Should be 42: " << mstack.top() << std::endl;
	std::cout << "Showing all elements" << std::endl;
	printContainer(mstack);

	std::cout << "Testing iterators" << std::endl;
	MutantStack<int>::iterator itBegin = mstack.begin();
	MutantStack<int>::iterator itEnd = mstack.end();
	std::cout << "While itBegin != itEnd" << std::endl;
	while (itBegin != itEnd)
	{
		std::cout << *itBegin << " ";
		itBegin++;
	}
	std::cout << std::endl;
	itBegin = mstack.begin();
	std::cout << "While itEnd != itBegin" << std::endl;
	while (itEnd != itBegin)
	{
		itEnd--;
		std::cout << *itEnd << " ";
	}
	std::cout << std::endl;
	std::cout << "Finished testing iterators" << std::endl;
}

int main() {
	testsMutantStack();
	testComparisonOtherList();
	return 0;
}