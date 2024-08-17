#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->_fixedPointNum = 0;
}

Fixed::Fixed(Fixed const &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj; // esse vai chamar o operador de atribuição
}

Fixed & Fixed::operator=(Fixed const &obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj) {	this->_fixedPointNum = obj.getRawBits(); }
	return *this; // retorna um ponteiro de referencia para o mesmo
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPointNum);
}

void	Fixed::setRawBits(int const raw)
{
    this->_fixedPointNum = raw;
}


Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}