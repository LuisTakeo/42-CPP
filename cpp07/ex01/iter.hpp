#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <cstdlib>

template <typename TType>
void iter(TType const *array, int len, void (*f)(TType const &))
{
  for (int i = 0; i < len; i++)
    f(array[i]);
}

template <typename TType>
void iter(TType *array, int len, void (*f)(TType &))
{
  for (int i = 0; i < len; i++)
    f(array[i]);
}

template <typename TType>
void printRandomColor(TType const &value)
{
  static int i = 0;
  int color;
  std::string colorCode;

  if (!i++)
    srand(time(NULL));
  color = rand() % 7;
  switch(color)
  {
    case 0:
      colorCode = "\033[0;31m";
      break;
    case 1:
      colorCode = "\033[0;32m";
      break;
    case 2:
      colorCode = "\033[0;33m";
      break;
    case 3:
      colorCode = "\033[0;34m";
      break;
    case 4:
      colorCode = "\033[0;35m";
      break;
    case 5:
      colorCode = "\033[0;36m";
      break;
    default:
      colorCode = "\033[0;37m";
      break;
  }
  std::cout << colorCode << value << "\033[0m" << std::endl;
}

template <typename TValue>
void increment(TValue &value)
{
  value++;
}

#endif