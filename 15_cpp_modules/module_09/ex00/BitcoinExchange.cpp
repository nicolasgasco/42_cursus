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
    data_file.open(DB_NAME);

    if (!data_file.is_open())
        throw std::runtime_error(std::string("Could not open file"));

    std::string line;
    std::getline(data_file, line); // Skip first line (header)
    while (std::getline(data_file, line))
    {
        DbLine db_line;
        db_line.date = line.substr(0, line.find(","));
        db_line.value = std::atof(line.substr(line.find(",") + 1).c_str());
        this->_rates.push_back(db_line);
    }
    data_file.close();
}

void BitcoinExchange::output_values(std::string const &input_file_name)
{
    std::fstream input_file;
    input_file.open(input_file_name);

    if (!input_file.is_open())
        throw std::runtime_error(std::string("Error: Could not open input file"));

    std::string line;
    while (std::getline(input_file, line))
    {
        // Skip header if present
        if (line.find_first_of("0123456789,.") == std::string::npos)
            continue;

        // Replace , before parsing to float
        if (line.find(",") != std::string::npos)
            line.replace(line.find(","), 1, ".");
        if (this->_is_input_line_valid(line))
        {
            float value = this->_calc_value(line);
            if (value == -1)
                std::cout << RED << "❌ Invalid input: " << (line.size() ? line : "n/a") << NOCOL << std::endl;
            else
                this->_output_formatted_value(line, value);
        }
        else
            std::cout << RED << "❌ Invalid input: " << (line.size() ? line : "n/a") << NOCOL << std::endl;
    }
    input_file.close();
}

float BitcoinExchange::_calc_value(std::string const &line) const
{
    std::string date_str = line.substr(line.find_first_not_of(" "));
    date_str = line.substr(0, line.find(" |"));

    std::string line_str = line.substr(line.find("| ") + 2);
    float value = std::atof(line_str.c_str());

    float result = -1;
    std::deque<DbLine>::const_iterator it = this->_rates.begin();
    while (it != this->_rates.end())
    {
        if (date_str == it->date)
        {
            result = value * it->value;
            break;
        }
        else if (date_str < it->date || it == this->_rates.end())
        {
            // If date is before first date in db
            if (it == this->_rates.begin())
            {
                result = -1;
                break;
            }

            it--;
            result = value * it->value;
            break;
        }
        it++;
    }
    return result;
}

void BitcoinExchange::_output_formatted_value(std::string const &line, float const &value) const
{
    std::string date_str = line.substr(line.find_first_not_of(" "));
    date_str = line.substr(0, line.find("|"));
    date_str = date_str.substr(0, date_str.find_last_not_of(" ") + 1);

    std::cout << "✅: " << GREEN << date_str << " ............................................." << std::fixed << std::setprecision(2) << value << NOCOL << std::endl;
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

    if (t.tm_mon == -1 || t.tm_mday == -1 || t.tm_year == -1)
        return false;

    if (ss.fail())
        return false;
    return true;
}

bool BitcoinExchange::_is_value_valid(std::string const &value_str) const
{
    unsigned int dot_count = 0;
    for (size_t i = 0; i < value_str.size(); i++)
    {
        if (value_str[i] == '.')
        {
            dot_count++;
            continue;
        }
        if (!std::isdigit(value_str[i]))
            return false;
    }

    if (dot_count > 1)
        return false;

    double num_double = std::atof(value_str.c_str());

    if (num_double < 0 || num_double > 1000)
        return false;

    return true;
}
