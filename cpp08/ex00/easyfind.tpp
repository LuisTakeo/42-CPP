#include "easyfind.hpp"

template <typename TContainer>
typename TContainer::iterator    easyfind(TContainer &container, int num)
{
    typename TContainer::iterator   it;

    it = std::find(container.begin(), container.end(), num);
    if (it == container.end())
    {
        std::stringstream ss;
        ss << "The value " << num << " has not been found";
        throw std::runtime_error(ss.str());
    }
    return (it);
};

// template <typename TKey = int, typename TValue = int>
// typename std::map<TKey, TValue>::iterator    easyfind(std::map<TKey, TValue> &container, int num)
// {
//     std::map::iterator   it;

//     it = container.find(num);
//     if (it == container.end())
//         throw std::runtime_error("Not found");
//     return (it);

template <typename TContainer>
void printContainer(TContainer const &container)
{
	typedef typename TContainer::const_iterator const_iterator;
	for (const_iterator it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

}

template <typename TContainer>
void printContainer(TContainer &container)
{
	typedef typename TContainer::iterator iterator;
	for (iterator it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}
