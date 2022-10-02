#include "span.hpp"

#define RED "\033[0;31m"
#define NOCOL "\033[0m"

int main(void)
{
    std::cout << "TESTING FUNC TO ADD NUMBERS:" << std::endl;
    Span sp = Span(5);
    std::cout << std::endl;

    try
    {
        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(11);
    }
    catch (std::exception &e)
    {
        std::cout << RED << "Error: " << e.what() << NOCOL << std::endl;
    }

    std::cout << std::endl;
    std::cout << "TESTING SHORTEST SPAN:" << std::endl;
    Span sp2 = Span(0);

    try
    {
        sp2.shortestSpan();
    }
    catch (std::exception &e)
    {
        std::cout << RED << "Error: " << e.what() << NOCOL << std::endl;
    }
    std::cout << std::endl;

    Span sp3 = Span(1);

    try
    {
        sp3.shortestSpan();
    }
    catch (std::exception &e)
    {
        std::cout << RED << "Error: " << e.what() << NOCOL << std::endl;
    }
    std::cout << std::endl;

    return (0);
}