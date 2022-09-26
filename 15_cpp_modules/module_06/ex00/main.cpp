#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: wrong arguments" << std::endl;
        return (1);
    }

    std::string strArg = argv[1];

    // INT
    std::cout << "int: ";
    try
    {
        int intArg = std::stoi(strArg);
        std::cout << intArg << std::endl;
    }
    catch (...)
    {
        std::cout << "impossible" << std::endl;
    }

    // CHAR
    std::cout << "char: ";
    try
    {
        int intArg = std::stoi(strArg);
        std::cout << intArg << std::endl;

        std::cout << "char: ";
        if (intArg <= 31)
        {
            std::cout << "non displayable" << std::endl;
        }
        else if (intArg > 127)
        {
            std::cout << "impossible" << std::endl;
        }
        else
        {
            char charArg = static_cast<char>(intArg);
            std::cout << "'" << charArg << "'" << std::endl;
        }
    }
    catch (...)
    {
        if (strArg.length() == 1)
        {
            char charArg = static_cast<char>(strArg.at(0));
            std::cout << "char: '" << charArg << "'" << std::endl;
        }
        else
        {
            std::cout << "char: imposible" << std::endl;
        }
    }

    // FLOAT
    std::cout << "float: ";
    try
    {
        float floatArg = std::stof(strArg);
        std::cout << floatArg << std::endl;
    }
    catch (...)
    {
        std::cout << "impossible" << std::endl;
    }

    // DOUBLE
    std::cout << "double: ";
    try
    {
        double doubleArg = std::stod(strArg);
        std::cout << doubleArg << std::endl;
    }
    catch (...)
    {
        std::cout << "impossible" << std::endl;
    }
    return (0);
}