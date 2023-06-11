#include <iostream>
#include <stdexcept>
#include "BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
    try
    {
        if (argc != 2)
            throw std::runtime_error(std::string("Please provide an argument"));

        BitcoinExchange exchange;

        exchange.output_values(argv[1]);

        // std::cout << std::endl << "COPY CONSTRUCTOR TEST:" << std::endl;
        // BitcoinExchange exchange2(exchange);

        // exchange2.output_values(argv[1]);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}