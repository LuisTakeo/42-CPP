#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <exception>
#include <string>
#include <list>
#include <deque>
#include <algorithm>

class PMergeMe
{
    private:
        std::list<int>  _list;
        std::deque<int> _deque;

        PMergeMe();

    public:
        PMergeMe(PMergeMe const &other);
        -PMergeMe();
        PMergeMe &operator=(PMergeMe const &other);

        void    run(const char **av);
}


#endif