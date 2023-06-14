#pragma once
#ifndef __BitcoinExchange_H__
#define __BitcoinExchange_H__

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

#include <deque>

#define DB_NAME "data.csv"

#define GREEN "\033[0;32m"
#define NOCOL "\033[0m"
#define RED "\033[0;31m"

struct DbLine
{
    std::string date;
    float value;
};

class BitcoinExchange
{

public:
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange const &src);

    ~BitcoinExchange();

    BitcoinExchange &operator=(const BitcoinExchange &src);

    void output_values(std::string const &input_file_name);

private:
    std::deque<DbLine> _rates;

    void _parse_db();
    float _calc_value(std::string const &line) const;
    void _output_formatted_value(std::string const &line, float const &value) const;

    bool _is_date_valid(std::string const &date_str) const;
    bool _is_input_line_valid(std::string const &line) const;
    bool _is_value_valid(std::string const &value_str) const;
};

#endif
