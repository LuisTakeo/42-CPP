#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <exception>
#include <string>
#include <list>
#include <deque>
#include <algorithm>
#include <climits>
#include <cstdio>

class PMergeMe
{
    private:
        std::list<int>  _list;
        std::deque<int> _deque;

        bool            isNumber(char *str);
        void            putValues(char **av);

    public:
        PMergeMe();
        PMergeMe(PMergeMe const &other);
        ~PMergeMe();
        PMergeMe &operator=(PMergeMe const &other);

        void    run(char **av);
};


#endif