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
    }
    file.close();
}

bool BitcoinExchange::isInvalidDate(std::string &line)
{
    int year, month, day;
    float value;
    if (std::sscanf(line.c_str(), "%d-%d-%d | %f", &year, &month, &day, &value) != 4)
        return true;
    if (year == 2009 && month == 1 && day == 1)
        return true;

    bool validMonth = month >= 1 && month <= 12,
        validDay = day >= 1 && day <= 31,
        validYear = year >= 2009 && year <= 2024;
    if (not validMonth || not validDay || not validYear)
        return true;

    bool bissextile = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    int daysInMonth[] = {31, 28 + bissextile, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    validDay = day <= daysInMonth[month - 1];
    if (not validDay)
        return true;
    return false;
}

bool BitcoinExchange::isInvalidFormat(std::string &line)
{
    bool isInvalidFormat = line.length() < MIN_SIZE || line[4] != '-' || line[7] != '-'
        || line[10] != ' ' || line[11] != '|' || line[12] != ' ';
    if (isInvalidFormat)
        return true;
    return false;

}

bool BitcoinExchange::isValidInput(std::string &line)
{
    if (isInvalidFormat(line) || isInvalidDate(line))
        return false;
    return true;
}

float BitcoinExchange::convertBitcoin(std::string &date, float value)
{
    if (value > 1000)
        throw std::invalid_argument("Error: value too high");
    if (value < 0)
        throw std::invalid_argument("Error: not a positive value");
    if (value == 0)
        return 0.0f;

    std::map<std::string, float>::iterator it = this->_data.lower_bound(date);
    if (date != it->first)
        --it;

    return value * it->second;
}

void BitcoinExchange::searchAndPrintExchange(std::string &line)
{
    if (not isValidInput(line))
        throw std::invalid_argument("Error: Bad input => '" + line + "'");

    size_t space = line.find(' ');
    std::string date = line.substr(0, space);
    std::string valueText = line.substr(line.find('|') + 2, std::string::npos);

    float convertedValue = convertBitcoin(date, std::strtof(valueText.c_str(), NULL));
    std::cout << std::fixed << std::setprecision(2) << convertedValue << std::endl;
}

void BitcoinExchange::printExchanges(std::ifstream &file)
{
    std::string line;
    while (std::getline(file, line))
    {
        try
        {
            if (line[line.size() - 1] == '\r' || line[line.size() - 1] == '\n')
                line.erase(line.size() - 1);
            searchAndPrintExchange(line);
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}

void BitcoinExchange::validateFirstLine(std::ifstream &file)
{
    std::string line;
    std::getline(file, line);

    if (line.empty())
    {
        file.close();
        throw std::invalid_argument("Error: invalid file format 0");
    }
    if (line[line.size() - 1] == '\r' || line[line.size() - 1] == '\n')
        line.erase(line.size() - 1);

    if (std::strcmp("date | value", line.c_str()))
    {
        file.close();
        throw std::invalid_argument("Error: invalid file format 1");
    }
}

void BitcoinExchange::printFile(std::string const &filename)
{
    std::ifstream file(filename.c_str());

    if (!file.is_open())
        throw std::invalid_argument("Error: file not found");

    validateFirstLine(file);
    printExchanges(file);

    file.close();
}
