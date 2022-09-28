#include <iostream>
#include "ScalarConversion.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Error: wrong arguments" << std::endl;
        return (1);
    }
    ScalarConversion conversion(argv[1]);

    try
    {
        switch (conversion.getType())
        {
        case t_int:
            std::cout << "Type is int\n"
                      << std::endl;
            conversion.outputConversions(std::stoi(conversion.getStrArg()));
            break;
        case t_char:
            std::cout << "Type is char\n"
                      << std::endl;
            conversion.outputConversions(conversion.getStrArg().at(0));
            break;
        case t_float:
            std::cout << "Type is float\n"
                      << std::endl;
            conversion.outputConversions(std::stof(conversion.getStrArg()));
            break;
        case t_double:
            std::cout << "Type is double\n"
                      << std::endl;
            conversion.outputConversions(std::stod(conversion.getStrArg()));
            break;
        default:
            std::cout << "Error: unknown type\n"
                      << std::endl;
            return (1);
        }
    }
    catch (...)
    {
        std::cout << "Error: invalid argument" << std::endl;
    }
}