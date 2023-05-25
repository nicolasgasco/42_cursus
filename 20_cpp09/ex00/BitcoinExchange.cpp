#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    this->_parse_db();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
    *this = src;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
    this->_rates = src._rates;
    return *this;
}

void BitcoinExchange::_parse_db()
{
    std::fstream data_file;
    data_file.open("data.csv");

    if (!data_file.is_open())
        throw std::runtime_error(std::string("Could not open file"));

    std::string line;
    unsigned int i = 0;
    while (std::getline(data_file, line))
    {
        if (i == 0)
        {
            i++;
            continue;
        }

        DbLine db_line;

        std::string date_str = line.substr(0, line.find(","));

        float value = std::stof(line.substr(line.find(",") + 1));

        db_line.date = date_str;
        db_line.value = value;
        this->_rates.push_back(db_line);

        i++;
    }
    data_file.close();
}

void BitcoinExchange::output_values(std::string const &input_file_name)
{
    std::fstream input_file;
    input_file.open(input_file_name);

    if (!input_file.is_open())
        throw std::runtime_error(std::string("Could not open input file"));

    std::string line;
    unsigned int i = 0;
    while (std::getline(input_file, line))
    {
        if (i == 0)
        {
            i++;
            continue;
        }

        if (this->_is_input_line_valid(line))
            std::cout << "✅: " << GREEN << this->_calc_value(line) << NOCOL << std::endl;
        else
            std::cout << RED << "❌ Invalid input: " << line << NOCOL << std::endl;
        i++;
    }
    input_file.close();
}

std::string BitcoinExchange::_calc_value(std::string const &line) const
{
    std::string date_str = line.substr(0, line.find(" |"));
    float value = std::stof(line.substr(line.find("| ") + 2));

    std::string result_line = date_str + " ......................................................";

    std::string formatted_value;
    std::list<DbLine>::const_iterator it = this->_rates.begin();
    while (it != this->_rates.end())
    {
        std::string rate_date_str = it->date;
        if (date_str == rate_date_str)
        {
            float result = value * it->value;
            formatted_value = std::to_string(result);
            break;
        }
        else if (date_str < rate_date_str || it->date == this->_rates.back().date)
        {
            if (it == this->_rates.begin())
            {
                formatted_value = "N/A";
                break;
            }

            std::list<DbLine>::const_iterator it_rev = it;
            it_rev--;

            float result = value * it_rev->value;
            formatted_value = std::to_string(result);
            break;
        }
        it++;
    }

    // Remove trailing zeros
    if (formatted_value.find(".") != std::string::npos)
    {
        formatted_value = formatted_value.substr(0, formatted_value.find(".") + 3);
        formatted_value = formatted_value.substr(0, formatted_value.find_last_not_of('0') + 1);
    }

    result_line += formatted_value;

    return result_line;
}

bool BitcoinExchange::_is_input_line_valid(std::string const &line) const
{
    if (line.empty())
        return false;

    if (line.find("|") == std::string::npos)
        return false;

    std::string date_str = line.substr(0, line.find(" |"));
    if (!this->_is_date_valid(date_str))
        return false;

    std::string value_str = line.substr(line.find("| ") + 2);
    if (!this->_is_value_valid(value_str))
        return false;

    return true;
}

bool BitcoinExchange::_is_date_valid(std::string const &date_str) const
{
    std::tm t = {};
    std::istringstream ss(date_str.c_str());
    ss >> std::get_time(&t, "%Y-%m-%d");

    if (ss.fail())
        return false;
    return true;
}

bool BitcoinExchange::_is_value_valid(std::string const &value_str) const
{
    float num_float;
    try
    {
        num_float = std::stof(value_str);
    }
    catch (std::exception &e)
    {
        return false;
    }

    if (num_float < 0 || num_float > 1000)
        return false;

    return true;
}