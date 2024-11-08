#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

std::string ScalarConverter::getType(const std::string &str)
{
	if (isChar(str))
		return ("char");
	if (isInt(str))
		return ("int");
	if (isFloat(str))
		return ("float");
	if (isDouble(str))
		return ("double");
	if (isPseudoLiteral(str))
		return ("pseudo literal");
	return ("invalid");
}

bool ScalarConverter::isChar(const std::string &str)
{
	if (str.length() == 1 && !std::isdigit(str[0]))
		return (true);
	return (false);
}

bool ScalarConverter::isInt(const std::string &str)
{
	char		*endptr;
	long int	n;

	if (str.length() == 1 && std::isdigit(str[0]))
		return (true);
	n = std::strtol(str.c_str(), &endptr, 10);
	if (*endptr != '\0')
		return (false);
	if (n > std::numeric_limits<int>::max() || n < std::numeric_limits<int>::min())
		return (false);
	return (true);
}

bool ScalarConverter::isFloat(const std::string &str)
{
	char		*endptr;
	float		n;

	n = std::strtof(str.c_str(), &endptr);
	if (*endptr != '\0')
		return (false);
	if (n == std::numeric_limits<float>::infinity() || n == -std::numeric_limits<float>::infinity()
		|| !str.compare("nanf"))
		return (false);
	return (true);
}

bool ScalarConverter::isDouble(const std::string &str)
{
	char		*endptr;
	double		n;

	n = std::strtod(str.c_str(), &endptr);
	if (*endptr != '\0')
		return (false);
	if (n == std::numeric_limits<double>::infinity() || n == std::numeric_limits<double>::quiet_NaN())
		return (false);
	return (true);
}

bool ScalarConverter::isPseudoLiteral(const std::string &str)
{
	if (!str.compare("inff") || !str.compare("+inff") || !str.compare("-inff")
		|| !str.compare("nanf") || !str.compare("inf") || !str.compare("+inf")
		|| !str.compare("-inf") || !str.compare("nan"))
		return (true);
	return (false);
}

// TODO: Implement this method
// This method should call the appropriate conversion method based on the input string
// The conversion methods should be static and private
// The conversion methods should be named toChar, toInt, toFloat, and toDouble
// The conversion methods should take a const std::string & as a parameter
void ScalarConverter::convert(const std::string &str)
{
	std::string	type;

	type = getType(str);
	if (type == "invalid")
	{
		std::cerr << "Invalid input" << std::endl;
		return ;
	}
	ScalarConverter::toChar(str, type);
}

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
void ScalarConverter::toChar(const std::string &str, const std::string &type)
{
	char c = -1;

	std::cout << "char: ";
	if (type == "char" || type == "int" || type == "float")
	{
		if (type == "char")
			c = static_cast<char>(str[0]);
		else
		{
			char	*endptr;
			double	n = std::strtod(str.c_str(), &endptr);
			if (n < 0 || n > 255 || n == std::numeric_limits<double>::quiet_NaN())
			{	std::cout << "impossible" << std::endl; return ;	}
			c = static_cast<char>(n);
		}
		if (std::isprint(c))
			std::cout << "'" << c << "'";
		else
			std::cout << "Non displayable"; // CORRIGIR
	}
	else
		std::cout << "impossible";
	std::cout << std::endl;
}

// TODO: Implement this method
// This method should convert the input string to an int
// If the input string is not a valid int, this method should print "impossible"
// else, this method should print "int: <int>"
void ScalarConverter::toInt(const std::string &str, const std::string &type)
{
	(void)str;
	(void)type;
	std::cout << "Int: ";


	std::cout << std::endl;
}


// TODO: Implement this method
// This method should convert the input string to a float
// If the input string is not a valid float, this method should print "impossible"
// else, this method should print "float: <float>.0f"
// If the input is a inff or +inff or -inff,
// this method should print "float: inff" or "float: +inff" or "float: -inff"
// If the input is a nanf, this method should print "float: nanf"
void ScalarConverter::toFloat(const std::string &str, const std::string &type)
{
	(void)str;
	(void)type;
	std::cout << "Float: ";


	std::cout << std::endl;
}

// TODO: Implement this method
// This method should convert the input string to a double
// If the input string is not a valid double, this method should print "impossible"
// else, this method should print "double: <double>.0"
// If the input is a inf or +inf or -inf,
// this method should print "double: inf" or "double: +inf" or "double: -inf"
// If the input is a nan, this method should print "double: nan"
void ScalarConverter::toDouble(const std::string &str, const std::string &type)
{
	(void)str;
	(void)type;
	std::cout << "Double: ";


	std::cout << std::endl;
}
