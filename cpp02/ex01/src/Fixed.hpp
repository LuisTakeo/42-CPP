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

    Fixed & operator=(Fixed const &obj); // Operador de atribuição

    // Getters - Setters
    int		getRawBits(void) const;
	void	setRawBits(int const raw);

    // Conversores
    int     toInt(void) const;
    float   toFloat(void) const;
};

std::ostream &operator<<(std::ostream &os, Fixed const &fix);

#endif