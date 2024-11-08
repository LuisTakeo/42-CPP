#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
	private:
		static void toChar(const std::string &str);
		static void toInt(const std::string &str);
		static void toFloat(const std::string &str);
		static void toDouble(const std::string &str);
	public:
		static void convert(const std::string &str);
}


#endif