#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#define MIN_SIZE 14

#include <iostream>
#include <string>
#include <cstring>
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

		void	setDatabase();
		void	validateFirstLine(std::ifstream &file);
		void	printExchanges(std::ifstream &file);
		void	searchAndPrintExchange(std::string &line);
		float	convertBitcoin(std::string &date, float value);
		// validation methods
		bool	isValidInput(std::string &line);
		bool	isInvalidFormat(std::string &line);
		bool	isInvalidDate(std::string &line);

	public:
		BitcoinExchange();
		BitcoinExchange(std::string database);
		BitcoinExchange(BitcoinExchange const &other);
		~BitcoinExchange();
		BitcoinExchange &operator=(BitcoinExchange const &other);

		// outside file methods
		void	printFile(std::string const &filename);
};

#endif