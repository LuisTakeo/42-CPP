#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &str)
{
	(void)str;
	// TODO: Implement this method
	// This method should call the appropriate conversion method based on the input string
	// The conversion methods should be static and private
	// The conversion methods should be named toChar, toInt, toFloat, and toDouble
	// The conversion methods should take a const std::string & as a parameter
	str.length();
}

void ScalarConverter::toChar(const std::string &str)
{
	(void)str;
	// TODO: Implement this method
	// This method should convert the input string to a char
	// If the input string is not a valid char, this method should print "impossible"
	// If the input is a literal char and its printable, this method should print "char: '<char>'"
	// If the input is a literal int or float and its printable, this method should print "char: '<char>'"
	// If the input is a literal int or float and its not printable,
	// this method should print "char: Non displayable"
	// If the input is a literal double and its not printable, this method should print "char: Non displayable"
	// If the input is a literal double and its printable, this method should print "char: '<char>'"
	// If the input is a literal double and its not representable as a char, this method should print "char: impossible"
}

void ScalarConverter::toInt(const std::string &str)
{
	(void)str;
	// TODO: Implement this method
	// This method should convert the input string to an int
	// If the input string is not a valid int, this method should print "impossible"
	// else, this method should print "int: <int>"
}

void ScalarConverter::toFloat(const std::string &str)
{
	(void)str;
	// TODO: Implement this method
	// This method should convert the input string to a float
	// If the input string is not a valid float, this method should print "impossible"
	// else, this method should print "float: <float>.0f"
	// If the input is a inff or +inff or -inff,
	// this method should print "float: inff" or "float: +inff" or "float: -inff"
	// If the input is a nanf, this method should print "float: nanf"
}

void ScalarConverter::toDouble(const std::string &str)
{
	(void)str;
	// TODO: Implement this method
	// This method should convert the input string to a double
	// If the input string is not a valid double, this method should print "impossible"
	// else, this method should print "double: <double>.0"
	// If the input is a inf or +inf or -inf,
	// this method should print "double: inf" or "double: +inf" or "double: -inf"
	// If the input is a nan, this method should print "double: nan"
}
