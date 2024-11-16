#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#define COLOR_DEQUE "\033[1;31m"
#define COLOR_VECTOR "\033[1;32m"
#define COLOR_TITLE "\033[1;33m"
#define COLOR_RESET "\033[0m"

#include <iostream>
#include <exception>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <climits>
#include <cstdio>
#include <ctime>
#include <iomanip>

class PMergeMe
{
    private:
        std::vector<int>  _vector;
        std::deque<int> _deque;

        bool            isNumber(char *str);
        void            putValues(char **av);

        template <typename TContainer>
        void    mergeInsertionSort(TContainer &container);

        template <typename TContainer>
        int     findSmallest(TContainer &container, TContainer &larger);

        template <typename TContainer>
        void    printContainer(TContainer &container);


    public:
        PMergeMe();
        PMergeMe(PMergeMe const &other);
        ~PMergeMe();
        PMergeMe &operator=(PMergeMe const &other);

        void    run(char **av);
};

template <typename TContainer>
void    PMergeMe::printContainer(TContainer &container)
{
    for (typename TContainer::iterator it = container.begin(); it != container.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}



template <typename TContainer>
void PMergeMe::mergeInsertionSort(TContainer &container)
{
    size_t size = container.size();
    if (size < 2)
        return;

    TContainer larger, smaller;
    // Divide the container into two parts
    for (size_t i = 0; i < size; i += 2)
    {
        if (i + 1 < size)
        {
            larger.push_back(std::max(container[i], container[i + 1]));
            smaller.push_back(std::min(container[i], container[i + 1]));
        }
        else
            larger.push_back(container[i]);
    }

    // Recursive call to divide the larger part
    mergeInsertionSort(larger);

    // Clear the container and copy the sorted larger part
    container.clear();
    container = larger;

    // Insert the elements from the smaller part into the sorted container
    typedef typename TContainer::iterator iterator;
    for (size_t i = 0; i < smaller.size(); ++i)
    {
        iterator insertPos = std::lower_bound(container.begin(), container.end(), smaller[i]);
        container.insert(insertPos, smaller[i]);
    }
}



#endif