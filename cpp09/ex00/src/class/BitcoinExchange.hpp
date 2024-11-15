#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <exception>
#include <algorithm>
#include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_data;
		std::string						_input;
	public:
		BitcoinExchange();
		BitcoinExchange(std::string database);
		BitcoinExchange(BitcoinExchange const &other);
		~BitcoinExchange();
		BitcoinExchange &operator=(BitcoinExchange const &other);

		void	setDatabase();

		// outside file methods
		void	printFile(std::string filename);

};

#endif