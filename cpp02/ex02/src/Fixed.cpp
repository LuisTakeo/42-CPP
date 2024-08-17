#include "Fixed.hpp"

// Construtores
Fixed::Fixed() { this->_fixedPointNum = 0; }

Fixed::Fixed(const int num) { this->setRawBits(num << this->_fractionalBits); }

Fixed::Fixed(const float num) { this->setRawBits(roundf(num * (1 << this->_fractionalBits))); }

Fixed::Fixed(Fixed const &obj) { *this = obj; }

// Destructor
Fixed::~Fixed() { }

// Operador de associação
Fixed & Fixed::operator=(Fixed const &obj)
{
    if (this != &obj) {	this->setRawBits(obj.getRawBits()); }
	return *this;
}

// Getters - Setters
int	Fixed::getRawBits(void) const {	return (this->_fixedPointNum); }

void	Fixed::setRawBits(int const raw) { this->_fixedPointNum = raw; }

// Conversores
int Fixed::toInt(void) const { return (this->_fixedPointNum >> this->_fractionalBits); }

float   Fixed::toFloat(void) const { return ((float)this->_fixedPointNum / (float)(1 << this->_fractionalBits)); }

// Operadores Aritmeticos
Fixed   Fixed::operator+(Fixed const &obj) const { return (Fixed(this->toFloat() + obj.toFloat())); }
Fixed   Fixed::operator-(Fixed const &obj) const { return (Fixed(this->toFloat() - obj.toFloat())); }
Fixed   Fixed::operator*(Fixed const &obj) const { return (Fixed(this->toFloat() * obj.toFloat())); }
Fixed   Fixed::operator/(Fixed const &obj) const
{
    return (obj.getRawBits() ?
        (Fixed(this->toFloat() / obj.toFloat()))
        : Fixed(0));
}

// operadores de comparação
bool   Fixed::operator<(Fixed const &obj) const { return (this->getRawBits() < obj.getRawBits()); }
bool   Fixed::operator>(Fixed const &obj) const { return (this->getRawBits() > obj.getRawBits()); }
bool   Fixed::operator<=(Fixed const &obj) const { return (this->getRawBits() <= obj.getRawBits()); }
bool   Fixed::operator>=(Fixed const &obj) const { return (this->getRawBits() >= obj.getRawBits()); }
bool   Fixed::operator==(Fixed const &obj) const { return (this->getRawBits() == obj.getRawBits()); }
bool   Fixed::operator!=(Fixed const &obj) const { return (this->getRawBits() != obj.getRawBits()); }

// operadores de incremento - decremento
Fixed & Fixed::operator++(void)
{
    this->setRawBits(this->getRawBits() + 1);
    return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);
    this->setRawBits(this->getRawBits() + 1);
    return (temp);
}

Fixed & Fixed::operator--(void)
{
    this->setRawBits(this->getRawBits() - 1);
    return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
    this->setRawBits(this->getRawBits() - 1);
    return (temp);
}

// Static functions
Fixed		&	Fixed::min(Fixed &a, Fixed &b) { return (a < b ? a : b); }
Fixed		&	Fixed::max(Fixed &a, Fixed &b) { return (a > b ? a : b); }
const Fixed	&	Fixed::min(Fixed const &a, Fixed const &b) { return (a < b ? a : b); }
const Fixed	&	Fixed::max(Fixed const &a, Fixed const &b) { return (a > b ? a : b); }

// operador de inserção
std::ostream & operator<<(std::ostream &os, Fixed const &fix)
{
    os << fix.toFloat();
    return (os);
}
