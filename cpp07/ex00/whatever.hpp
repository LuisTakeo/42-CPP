#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

// templates are used to create a function that can work with many different types of data
// template receive a typename with the type of data that the function will receive
// A convention is to use T as the typename, but it can be any name
// Some others conventions are:
// E for element
// K for key
// V for value
// N for number
// T for type
// There are another conventions, one of them is to use the T followed by a informative name, like TType, TElement, TNumber, etc
template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename TMin>
TMin const &min (TMin const &a, TMin const &b) {   return (a < b ? a : b); }

template <typename TMax>
TMax const &max (TMax const &a, TMax const &b) {   return (a > b ? a : b); }


class Awesome
{
  public:
    Awesome(void) : _n(0) {}
    Awesome( int n ) : _n( n ) {}
    Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
    bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
    bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
    bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
    bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
    bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
    bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
    int get_n() const { return _n; }
  private:
    int _n;
};
std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }

#endif