#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
    int                 _fixedPointNum;
    static const int    _fractionalBits = 8;
public:
	Fixed(); // Construtor Padrão
	Fixed(const int num); // Construtor parametrizado -> int
	Fixed(const float num); // Construtor parametrizado -> float
	Fixed(Fixed const &obj); //Construtor de cópia
	~Fixed(); // Destruidor

	// Getters - Setters
	int						getRawBits(void) const;
	void					setRawBits(int const raw);

	// Conversores
	int						toInt(void) const;
	float					toFloat(void) const;

	Fixed				&	operator=(Fixed const &obj); // Operador de atribuição
    // Operadores aritméticos
	Fixed					operator+(Fixed const &obj) const;
	Fixed					operator-(Fixed const &obj) const;
	Fixed					operator*(Fixed const &obj) const;
	Fixed					operator/(Fixed const &obj) const;

	// operadores de comparação
	bool					operator>(Fixed const &obj) const;
	bool					operator<(Fixed const &obj) const;
	bool					operator>=(Fixed const &obj) const;
	bool					operator<=(Fixed const &obj) const;
	bool					operator==(Fixed const &obj) const;
	bool					operator!=(Fixed const &obj) const;

    // Operadores de incremento - decremento
    Fixed				&	operator++(void);
    Fixed					operator++(int);
    Fixed				&	operator--(void);
    Fixed					operator--(int);

	static Fixed		&	min(Fixed &a, Fixed &b);
	static Fixed		&	max(Fixed &a, Fixed &b);
	static const Fixed	&	min(Fixed const &a, Fixed const &b);
	static const Fixed	&	max(Fixed const &a, Fixed const &b);

};

std::ostream			&	operator<<(std::ostream &os, Fixed const &fix);

#endif