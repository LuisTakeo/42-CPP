#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <iterator>
# include <exception>
# include <sstream>

template <typename TContainer>
typename TContainer::iterator    easyfind(TContainer &container, int num);


// Esse template abaixo somente funciona no c++11 ou superior
// template <typename TKey = int, typename TValue = int>
// typename std::map<TKey, TValue>::iterator    easyfind(std::map<TKey, TValue> &container, int num)
// {
//     typename std::map<TKey, TValue>::iterator   it;

//     it = container.find(num);
//     if (it == container.end())
//         throw std::runtime_error("Not found");
//     return (it);
// };

# include "easyfind.tpp"

#endif