#include "Fixed.hpp"

// Construtores
Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->_fixedPointNum = 0;
}

Fixed::Fixed(const int num)
{
    std::cout << "Int constructor called" << std::endl;
    this->setRawBits(num << this->_fractionalBits);
}

Fixed::Fixed(const float num)
{
     std::cout << "Float constructor called" << std::endl;
     this->setRawBits(roundf(num * (1 << this->_fractionalBits)));
}

Fixed::Fixed(Fixed const &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj; // esse vai chamar o operador de atribuição
}

// Destructor
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

// Operador de associação
Fixed & Fixed::operator=(Fixed const &obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &obj) {	this->setRawBits(obj.getRawBits()); }
	return *this; // retorna um ponteiro de referencia para o mesmo
}

// Getters - Setters
int	Fixed::getRawBits(void) const {	return (this->_fixedPointNum); }

void	Fixed::setRawBits(int const raw) { this->_fixedPointNum = raw; }

// Conversores
int Fixed::toInt(void) const { return (this->_fixedPointNum >> this->_fractionalBits); }

float   Fixed::toFloat(void) const { return ((float)this->_fixedPointNum / (float)(1 << this->_fractionalBits)); }


// operador de inserção
std::ostream & operator<<(std::ostream &os, Fixed const &fix)
{
    os << fix.toFloat();
    return (os);
}
