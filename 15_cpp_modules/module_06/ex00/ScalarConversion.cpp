#include "ScalarConversion.hpp"
#include <iostream>
#include <iomanip>
#include <limits>

ScalarConversion::ScalarConversion(void) : strArg("")
{
}

ScalarConversion::ScalarConversion(std::string const &strArg) : strArg(strArg)
{
}

ScalarConversion::ScalarConversion(ScalarConversion const &src) : strArg(src.getStrArg())
{
    *this = src;
}

ScalarConversion::~ScalarConversion(void)
{
}

ScalarConversion &ScalarConversion::operator=(const ScalarConversion &src)
{
    std::cout << &src << std::endl;
    return *this;
}

std::string const &ScalarConversion::getStrArg(void) const
{
    return (this->strArg);
}

Type ScalarConversion::getType(void) const
{
    if (strArg.length() == 1)
    {
        if (strArg[0] >= 48 && strArg[0] <= 57)
            return (t_int);
        else
            return (t_char);
    }

    if (strArg.find("inff") != std::string::npos || strArg.find("nanf") != std::string::npos)
        return (t_float);

    if (strArg.find("inf") != std::string::npos || strArg.find("nan") != std::string::npos)
        return (t_double);

    if (strArg.find("f") != std::string::npos)
        return (t_float);

    if (strArg.find("f") == std::string::npos)
        return (t_double);

    return (t_unknown);
}

void ScalarConversion::outputConversions(int value) const
{
    // CHAR
    char charArg = static_cast<char>(value);
    if (value >= 0 && value <= 127)
    {
        if (std::isprint(charArg))
            std::cout << "char: '" << charArg << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
    }

    std::cout << "int: " << value << std::endl;
    std::cout << "float: " << static_cast<float>(value) << (value == static_cast<int>(value) ? ".0" : "") << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << (value == static_cast<int>(value) ? ".0" : "") << std::endl;
}

void ScalarConversion::outputConversions(char value) const
{

    // CHAR
    char charArg = static_cast<char>(value);
    if (std::isprint(charArg))
        std::cout << "char: '" << charArg << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    std::cout << "int: " << static_cast<int>(value) << std::endl;
    std::cout << std::setprecision(1) << std::fixed << "float: " << static_cast<float>(value) << (value == static_cast<int>(value) ? ".0" : "") << "f" << std::endl;
    std::cout << std::setprecision(1) << std::fixed << "double: " << static_cast<double>(value) << (value == static_cast<int>(value) ? ".0" : "") << std::endl;
}

void ScalarConversion::outputConversions(float value) const
{
    // CHAR
    char charArg = static_cast<char>(value);
    if (value >= 0 && value <= 127)
    {
        if (std::isprint(charArg))
            std::cout << "char: '" << charArg << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
    }

    // INT
    if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max())
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;

    // FLOAT
    std::cout << "float: " << value << (value == static_cast<int>(value) ? ".0" : "") << "f" << std::endl;

    // DOUBLE
    std::cout << "double: " << static_cast<double>(value) << (value == static_cast<int>(value) ? ".0" : "") << std::endl;
}

void ScalarConversion::outputConversions(double value) const
{
    // CHAR
    char charArg = static_cast<char>(value);
    if (value >= 0 && value <= 127)
    {
        if (std::isprint(charArg))
            std::cout << "char: '" << charArg << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
    }

    // INT
    if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max())
        std::cout
            << "int: " << static_cast<int>(value) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;

    // FLOAT
    std::cout << "float: " << static_cast<float>(value) << (value == static_cast<int>(value) ? ".0" : "") << "f" << std::endl;
    // DOUBLE
    std::cout << "double: " << value << (value == static_cast<int>(value) ? ".0" : "") << std::endl;
}
