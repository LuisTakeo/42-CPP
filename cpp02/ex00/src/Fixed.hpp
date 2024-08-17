#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
    int                 _fixedPointNum;
    static const int    _fractionalBits = 8;
public:
    Fixed(); // Construtor Padrão
    Fixed(Fixed const &obj); //Construtor de cópia
    ~Fixed(); // Destruidor

    Fixed & operator=(Fixed const &obj); // Operador de atribuição

    int		getRawBits(void) const;
	void	setRawBits(int const raw);
};




#endif