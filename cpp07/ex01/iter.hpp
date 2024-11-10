#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename TType>
void iter(TType *array, int len, void (*f)(TType const &))
{
  for (int i = 0; i < len; i++)
    f(array[i]);
}

#endif