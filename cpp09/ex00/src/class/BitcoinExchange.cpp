#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    this->_data = std::map<std::string, float>();
    this->_input = "data.csv";
    setDatabase();
}

BitcoinExchange::BitcoinExchange(std::string database)
{
    this->_data = std::map<std::string, float>();
    this->_input = database;
    setDatabase();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
{
    if (this != &other)
        *this = other;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other)
{
    this->_data = other._data;
    this->_input = other._input;
    return *this;
}

void BitcoinExchange::setDatabase()
{
    std::ifstream file(this->_input.c_str());

    if (!file.is_open())
        throw std::invalid_argument("Error: file not found");

    std::string line;
    std::getline(file, line);
    if (line != "date,exchange_rate")
        throw std::invalid_argument("Error: invalid file format");
    while (std::getline(file, line))
    {
        std::string key = line.substr(0, line.find(','));
        std::string value = line.substr(line.find(',') + 1);
        std::sscanf(value.c_str(), "%f", &this->_data[key]);
        std::cout << key << " " << std::fixed << std::setprecision(2) << this->_data[key] << std::endl;
    }
    file.close();
}


void BitcoinExchange::printFile(std::string filename)
{
    std::ifstream file(filename.c_str());

    if (!file.is_open())
        throw std::invalid_argument("Error: file not found");

    file.close();
}
