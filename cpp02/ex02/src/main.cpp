#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl; // valor 0
	std::cout << ++a << std::endl; // valor acrescido e mostrado na saida
	std::cout << a << std::endl; // valor atual
	std::cout << a++ << std::endl; // valor mostrado anterior e acrescido posteriormente
	std::cout << a << std::endl; // novo valor
	std::cout << b << std::endl; // valor de B
	std::cout << Fixed::max( a, b ) << std::endl; // retorno do maior
	// testes além da régua
	std::cout << "-----------------------" << std::endl;
	std::cout << "Testes próprios" << std::endl;
	std::cout << "Min (a, b): " << Fixed::min( a, b ) << std::endl; // retorno do menor
	std::cout << "--a: " << --a << std::endl; // valor decrescido e mostrado na saida
	std::cout << "--a: " << --a << std::endl; // valor decrescido e mostrado na saida
	std::cout << "a: " << a << std::endl; // valor atual
	std::cout << "a--: " << a-- << std::endl; // valor mostrado anterior e decrescido posteriormente
	std::cout << "a: " << a << std::endl; // novo valor
	std::cout << "-----------------------" << std::endl;
	std::cout << "0.3f + 10: " << (Fixed(0.3f) + Fixed(10)) << std::endl;
	std::cout << "13 - 10.8: " << (Fixed(13) - Fixed(10.8f)) << std::endl;
	std::cout << "0.3f * 10: " << (Fixed(0.3f) * Fixed(10)) << std::endl;
	std::cout << "13 * 10: " << (Fixed(13) * Fixed(10)) << std::endl;
	std::cout << "0 / 10: " << (Fixed(0) / Fixed(10)) << std::endl;
	std::cout << "10 / 0: " << (Fixed(10) / Fixed(0)) << std::endl;
	std::cout << "2 / 10: " << (Fixed(2) / Fixed(10)) << std::endl;
	std::cout << "2 / 4: " << (Fixed(2) / Fixed(4)) << std::endl;
	std::cout << "14 / 4: " << (Fixed(14) / Fixed(4)) << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "1.1 < 2: " << ((Fixed(1.1f) < Fixed(2)) ? "True" : "False") << std::endl;
	std::cout << "1.1 > 2: " << ((Fixed(1.1f) > Fixed(2)) ? "True" : "False") << std::endl;
	std::cout << "1.1 >= 2: " << ((Fixed(1.1f) >= Fixed(2)) ? "True" : "False") << std::endl;
	std::cout << "2.2 >= 2.2: " << ((Fixed(2.2f) >= Fixed(2.2f))  ? "True" : "False") << std::endl;
	std::cout << "1.1 <= 2: " << ((Fixed(1.1f) <= Fixed(2))  ? "True" : "False") << std::endl;
	std::cout << "2.2 <= 2.2: " << ((Fixed(2.2f) <= Fixed(2.2f))  ? "True" : "False") << std::endl;
	std::cout << "2.2 == 2.2: " << ((Fixed(2.2f) == Fixed(2.2f))  ? "True" : "False") << std::endl;
	std::cout << "2.3 == 2.2: " << ((Fixed(2.3f) == Fixed(2.2f))  ? "True" : "False") << std::endl;
	std::cout << "2.2 != 2.2: " << ((Fixed(2.2f) != Fixed(2.2f))  ? "True" : "False") << std::endl;
	std::cout << "2.3 != 2.2: " << ((Fixed(2.3f) != Fixed(2.2f))  ? "True" : "False") << std::endl;
	std::cout << "-----------------------" << std::endl;


	return 0;
}