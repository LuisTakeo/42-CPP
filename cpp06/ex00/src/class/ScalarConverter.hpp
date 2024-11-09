#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
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

		static int	countAfterPoint(const std::string &str);
		static void toChar(const std::string &str, const std::string &type);
		static void toInt(const std::string &str, const std::string &type);
		static void toFloat(const std::string &str, const std::string &type);
		static void toDouble(const std::string &str, const std::string &type);
		static void toPseudoLiteral(const std::string &str);

		/*
		* @brief Get the type of the string
		* @param str The string to get the type
		* @return The type of the string
		* @note If the string is invalid, return "Invalid input"
		*/
		static std::string getType(const std::string &str);
		static bool isChar(const std::string &str);
		static bool isInt(const std::string &str);
		static bool isFloat(const std::string &str);
		static bool isDouble(const std::string &str);
		static bool isPseudoLiteral(const std::string &str);
	public:
		/*
		* @brief Convert the string to char, int, float and double
		* @param str The string to convert
		* @return void
		* @note If the string is invalid, print "Invalid input" and return
		*/
		static void convert(const std::string &str);
};


#endif