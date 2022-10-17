#include <iostream>
#include <string>

#include "Array.hpp"

#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define NOCOL "\033[0m"

#define MAX_VAL 750

int main(void)
{
    std::cout << YELLOW << "NEW INT ARRAY WITH DEFAULT CONSTRUCTOR" << NOCOL << std::endl;
    Array<int> array;
    std::cout << std::endl;

    std::cout << "Outputting empty array:" << std::endl;
    std::cout << array << std::endl;

    std::cout << "Accessing index -1" << std::endl;
    try
    {
        std::cout << "Value of index -1 is: " << array[-1] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << RED << "Error: " << e.what() << NOCOL << std::endl;
        std::cout << std::endl;
    }

    std::cout << "Accessing index 1" << std::endl;
    try
    {
        std::cout << "Value of index 1 is: " << array[1] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << RED << "Error: " << e.what() << NOCOL << std::endl;
        std::cout << std::endl;
    }

    std::cout << YELLOW << "NEW ARRAY WITH PARAMETER CONSTRUCTOR (10)" << NOCOL << std::endl;
    Array<int> array2(10);
    std::cout << std::endl;

    std::cout << "Filling in array with sequential numbers..." << std::endl;
    for (unsigned int i = 0; i < array2.size(); i++)
        array2[i] = i + 1;

    std::cout << std::endl;
    std::cout << "Outputting filled array:" << std::endl;
    std::cout << array2 << std::endl;

    std::cout << "Accessing index 0" << std::endl;
    try
    {
        std::cout << "Value of index 0 is: " << array2[0] << std::endl;
        std::cout << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << std::endl;
    }

    std::cout << "Accessing index 9" << std::endl;
    try
    {
        std::cout << "Value of index 9 is: " << array2[9] << std::endl;
        std::cout << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << std::endl;
    }

    std::cout << "Accessing index 10" << std::endl;
    try
    {
        std::cout << "Value of index 10 is: " << array2[10] << std::endl;
        std::cout << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << RED << "Error: " << e.what() << NOCOL << std::endl;
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Copying Arrays:" << std::endl;
    Array<int> array3(array2);
    std::cout << array3 << std::endl;

    std::cout << std::endl;
    std::cout << YELLOW << "42 PROVIDED MAIN" << NOCOL << std::endl;
    std::cout << std::endl;
    {
        std::cout << "CREATING ARRAY OF WITH MAX_VAL INT VALUES:" << std::endl;
        Array<int>
            numbers(MAX_VAL);
        int *mirror = new int[MAX_VAL];
        srand(time(NULL));
        std::cout << "Filling it with random values..." << std::endl;
        std::cout << std::endl;

        for (int i = 0; i < MAX_VAL; i++)
        {
            const int value = rand();
            numbers[i] = value;
            mirror[i] = value;
        }
        std::cout << "Outputting numbers:" << std::endl;
        std::cout << numbers << std::endl;

        // SCOPE
        {
            std::cout << "New tmp and test arrays equal to numbers" << std::endl;
            Array<int> tmp = numbers;
            Array<int> test(tmp);

            std::cout << std::endl;
            std::cout << "Outputting tmp:" << std::endl;
            std::cout << tmp << std::endl;

            std::cout << "Outputting test:" << std::endl;
            std::cout << test << std::endl;
        }

        std::cout << "Should output an error if mirror and numbers are not identical..." << std::endl;
        for (int i = 0; i < MAX_VAL; i++)
        {
            if (mirror[i] != numbers[i])
            {
                std::cerr << "didn't save the same value!!" << std::endl;
                return 1;
            }
        }
        std::cout << std::endl;

        std::cout << "Invalid indexes:" << std::endl;
        try
        {
            numbers[-2] = 0;
        }
        catch (const std::exception &e)
        {
            std::cerr << RED << e.what() << '\n'
                      << NOCOL;
        }
        try
        {
            numbers[MAX_VAL] = 0;
        }
        catch (const std::exception &e)
        {
            std::cerr << RED << e.what() << '\n'
                      << NOCOL;
        }

        std::cout << std::endl;
        std::cout << "Filling up numbers with random values..." << std::endl;
        for (int i = 0; i < MAX_VAL; i++)
        {
            numbers[i] = rand();
        }

        std::cout << std::endl;
        delete[] mirror;
    }

    return (0);
}