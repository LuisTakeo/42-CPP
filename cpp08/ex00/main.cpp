#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>

int main()
{
    std::vector<int>	numVector;
    std::list<int>		numList;
	std::deque<int>		numDeque;
    std::map<int, int>  numMap;
    std::set<int>       numSet;

    for (int i = 0; i < 10; i++)
    {
        numVector.push_back(i);
        numList.push_back(i);
        numDeque.push_back(i);
        numMap[i] = i;
        numSet.insert(i);
    }

    std::cout << COLOR_GREEN << "Vector: " << COLOR_RESET;
    printContainer(numVector);
    try
    {
        std::cout << "Trying to find 5: ";
        std::cout << *easyfind(numVector, 5) << std::endl;
        std::cout << "Not Found test. Trying to find 100: ";
        std::cout << *easyfind(numVector, 100) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "---------------------------------" << std::endl;
    std::cout << COLOR_GREEN << "List: " << COLOR_RESET;
    printContainer(numList);
    try
    {
        std::cout << "Trying to find 2: ";
        std::cout << *easyfind(numList, 2) << std::endl;
        std::cout << "Not Found test. Trying to find 123: ";
        std::cout << *easyfind(numList, 123) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "---------------------------------" << std::endl;
    std::cout << COLOR_GREEN << "Deque: " << COLOR_RESET;
    printContainer(numDeque);
    try
    {
        std::cout << "Trying to find 4: ";
        std::cout << *easyfind(numDeque, 4) << std::endl;
        std::cout << "Not Found test. Trying to find 10: ";
        std::cout << *easyfind(numDeque, 10) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "---------------------------------" << std::endl;
    std::cout << COLOR_GREEN << "Set: " << COLOR_RESET;
    printContainer(numSet);
    try
    {
        std::cout << "Trying to find 6: ";
        std::cout << *easyfind(numSet, 6) << std::endl;
        std::cout << "Not Found test: Trying to find 11: ";
        std::cout << *easyfind(numSet, 11) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }


    // Os abaixo são comentados pois a função easyfind não foi implementada para map
    // std::cout << "Map: ";
    // try
    // {
    //     std::cout << easyfind(numMap, 5)->second << std::endl;
    // }
    // catch (std::exception &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }

    return (0);
}