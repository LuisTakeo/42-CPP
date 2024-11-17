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
        void    mergeBlocks(TContainer &container, size_t blockSize);

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
void PMergeMe::mergeBlocks(TContainer &container, size_t blockSize)
{
    size_t size = container.size();

    // Mesclagem de blocos
    for (size_t i = 0; i < size; i += 2 * blockSize)
    {
        size_t mid = std::min(i + blockSize, size);
        size_t end = std::min(i + 2 * blockSize, size);

        TContainer temp;
        typename TContainer::iterator it1 = container.begin() + i;
        typename TContainer::iterator it2 = container.begin() + mid;

        // Merged block de dois segmentos ordenados
        while (it1 != container.begin() + mid && it2 != container.begin() + end)
        {
            if (*it1 <= *it2)
                temp.push_back(*it1++);
            else
                temp.push_back(*it2++);
        }

        // Adicionar os elementos restantes
        while (it1 != container.begin() + mid)
            temp.push_back(*it1++);
        while (it2 != container.begin() + end)
            temp.push_back(*it2++);

        // Copiar os dados mesclados de volta
        std::copy(temp.begin(), temp.end(), container.begin() + i);
    }
}



template <typename TContainer>
void PMergeMe::mergeInsertionSort(TContainer &container)
{
    size_t size = container.size();
    if (size < 2)
        return;

    // Containers to store the elements
    TContainer ladder;  // Jacob's Ladder
    TContainer smaller; // Smaller elements

    // Dividing the container into blocks of 2 elements
    for (size_t i = 0; i < size; i += 2)
    {
        if (i + 1 < size)
        {
            int larger = std::max(container[i], container[i + 1]);
            int smallerElem = std::min(container[i], container[i + 1]);

            ladder.push_back(larger);  // Insert on ladder
            smaller.push_back(smallerElem);  // Insert on smaller
        }
        else
        {
            ladder.push_back(container[i]);  // Last element
        }
    }

    // Order the ladder recursively
    mergeInsertionSort(ladder);

    // Insert the smaller elements back into the ladder
    for (size_t i = 0; i < smaller.size(); ++i)
    {
        typename TContainer::iterator insertPos =
            std::lower_bound(ladder.begin(), ladder.end(), smaller[i]);
        ladder.insert(insertPos, smaller[i]);
    }

    // Update the container
    container = ladder;

    // Jacob's Ladder Sequence, merging the blocks
    size_t blockSize = 2;  // starts with 2 then doubles
    while (blockSize < size)
    {
        // Block merge
        mergeBlocks(container, blockSize);
        blockSize *= 2;  // Double the block size
    }
}

#endif