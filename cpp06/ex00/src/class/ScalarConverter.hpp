#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);


		static void toChar(const std::string &str, const std::string &type);
		static void toInt(const std::string &str, const std::string &type);
		static void toFloat(const std::string &str, const std::string &type);
		static void toDouble(const std::string &str, const std::string &type);
		static void toPseudoLiteral(const std::string &str);

		static std::string getType(const std::string &str);
		static bool isChar(const std::string &str);
		static bool isInt(const std::string &str);
		static bool isFloat(const std::string &str);
		static bool isDouble(const std::string &str);
		static bool isPseudoLiteral(const std::string &str);
	public:
		static void convert(const std::string &str);
};


#endif