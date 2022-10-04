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
        std::cout << "Add number 5" << std::endl;
        sp.addNumber(5);
        std::cout << "Add number 3" << std::endl;
        sp.addNumber(3);
        std::cout << "Add number 17" << std::endl;
        sp.addNumber(17);
        std::cout << "Add number 9" << std::endl;
        sp.addNumber(9);
        std::cout << "Add number 11" << std::endl;
        sp.addNumber(11);
        std::cout << "Add number 12" << std::endl;
        sp.addNumber(12);
    }
    catch (std::exception &e)
    {
        std::cout << RED << "Error: " << e.what() << NOCOL << std::endl;
    }

    std::cout << std::endl;
    std::cout << "TESTING SHORTEST SPAN:" << std::endl;
    Span sp2 = Span(0);
    std::cout << std::endl;

    std::cout << "Trying to find the short span of an empty vector:" << std::endl;
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
    std::cout << std::endl;

    std::cout << "Trying to find the short span of a vector with 1 element:" << std::endl;
    try
    {
        sp3.shortestSpan();
    }
    catch (std::exception &e)
    {
        std::cout << RED << "Error: " << e.what() << NOCOL << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Shortest span of sp is: " << sp.shortestSpan() << std::endl;
    std::cout << std::endl;

    std::cout << "Longest span of sp is: " << sp.longestSpan() << std::endl;
    std::cout << std::endl;

    std::cout << "SPAN WITH 2000 INTS:" << std::endl;
    Span sp4 = Span(2000);
    std::cout << std::endl;

    sp4.addRandomNumbers(2000);
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "Shortest span of sp4 is: " << sp4.shortestSpan() << std::endl;
    std::cout << std::endl;

    std::cout << "Longest span of sp4 is: " << sp4.longestSpan() << std::endl;
    std::cout << std::endl;

    std::cout << "TESTING COPY SPAN:" << std::endl;
    Span sp5 = Span(sp4);
    std::cout << std::endl;

    std::cout << "Printing copy:" << std::endl;
    sp5.outputVector();
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "Shortest span of sp5 is: " << sp5.shortestSpan() << std::endl;
    std::cout << std::endl;

    std::cout << "Longest span of sp5 is: " << sp5.longestSpan() << std::endl;
    std::cout << std::endl;

    return (0);
}