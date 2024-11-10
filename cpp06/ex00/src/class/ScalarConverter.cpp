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
	if (isPseudoLiteral(str))
		return ("pseudo literal");
	if (isChar(str))
		return ("char");
	if (isInt(str))
		return ("int");
	if (isFloat(str))
		return ("float");
	if (isDouble(str))
		return ("double");
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
	if (*endptr != 'f' || *(endptr + 1) != '\0')
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
	ScalarConverter::toInt(str, type);
	ScalarConverter::toFloat(str, type);
	ScalarConverter::toDouble(str, type);
}

void ScalarConverter::toChar(const std::string &str, const std::string &type)
{
	char c = -1;

	std::cout << "char: ";
	if (type == "pseudo literal")
	{	std::cout << "impossible" << std::endl; return ;	}
	if (type == "char")
		c = static_cast<char>(str[0]);
	else
	{
		char	*endptr;
		double	n = std::strtod(str.c_str(), &endptr);
		if (n < 0 || n > 255)
		{	std::cout << "impossible" << std::endl; return ;	}
		c = static_cast<char>(n);
	}
	if (std::isprint(c))
		std::cout << "'" << c << "'";
	else
		std::cout << "Non displayable";
	std::cout << std::endl;
}


void ScalarConverter::toInt(const std::string &str, const std::string &type)
{
	int	num = 0;

	std::cout << "Int: ";
	if (type == "pseudo literal")
	{	std::cout << "impossible" << std::endl; return ;	}
	if (type == "char")
		num = static_cast<int>(str[0]);

	long int value = std::strtol(str.c_str(), NULL, 10);
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
	{	std::cout << "impossible" << std::endl; return ;	}
	if (type == "int")
		num = static_cast<int>(value);
	if (type == "float")
		num = static_cast<int>(value);
	if (type == "double")
		num = static_cast<int>(value);
	std::cout << num;
	std::cout << std::endl;
}

int ScalarConverter::countAfterPoint(const std::string &str)
{
	size_t	pos = str.find('.');

	if (pos == std::string::npos)
		return (1);
	return (str.length() - pos - 1);
}

void ScalarConverter::toFloat(const std::string &str, const std::string &type)
{
	double value = 0.0f;

	std::cout << "Float: ";
	if (type == "pseudo literal")
	{
		if (str == "inf" || str == "+inf" || str == "-inf" || str == "nan")
			std::cout << str << "f" << std::endl;
		else
			std::cout << str << std::endl;
		return ;
	}
	if (type == "char")
		value = static_cast<float>(str[0]);
	else
	{
		value = std::strtod(str.c_str(), NULL);
		if (value > std::numeric_limits<float>::max())
		{	std::cout << "impossible" << std::endl; return ;	}
		// static_cast should not work with INT_MIN or INT_MAX
	}
	std::cout << std::fixed << std::setprecision(countAfterPoint(str)) << value << "f";

	std::cout << std::endl;
}

void ScalarConverter::toDouble(const std::string &str, const std::string &type)
{
	double num = 0.0;

	std::cout << "Double: ";
	if (type == "pseudo literal")
	{	std::cout << str << std::endl; return ;	}
	if (type == "char")
		num = static_cast<double>(str[0]);
	else
		num = std::strtod(str.c_str(), NULL);
	std::cout << std::fixed << std::setprecision(countAfterPoint(str)) << num;
	std::cout << std::endl;
}
