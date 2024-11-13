#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <exception>
# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(MutantStack const & src);
		~MutantStack();
		MutantStack & operator=(MutantStack const & rhs);

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin();
		iterator end();

		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		const_iterator begin() const;
		const_iterator end() const;
};

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const & src) : std::stack<T>(src) {}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T> & MutantStack<T>::operator=(MutantStack const & rhs)
{
	if (this != &rhs)
		std::stack<T>::operator=(rhs);
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{	return std::stack<T>::c.begin();	}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{	return std::stack<T>::c.end(); }

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{ return std::stack<T>::c.begin(); }

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

#endif