#include <iostream>
#include <string>

#include "Array.hpp"

#define MAX_VAL 750

int main(void)
{
    std::cout << "New array with default constructor" << std::endl;
    Array<int> array;
    std::cout << std::endl;

    std::cout << "Outputting empty array:" << std::endl;
    std::cout << array << std::endl;
    std::cout << std::endl;

    std::cout << "Accessing index -1" << std::endl;
    try
    {
        std::cout << "Value of index -1 is: " << array[-1] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << std::endl;
    }

    std::cout << "Accessing index 1" << std::endl;
    try
    {
        std::cout << "Value of index 1 is: " << array[1] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << std::endl;
    }

    std::cout << "New array with parameter constructor (10)" << std::endl;
    Array<int> array2(10);
    std::cout << std::endl;

    std::cout << "Filling in array with sequential numbers" << std::endl;
    for (unsigned int i = 0; i < array2.size(); i++)
        array2[i] = i + 1;

    std::cout << "Outputting filled array:" << std::endl;
    std::cout << array2 << std::endl;
    std::cout << std::endl;

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
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << std::endl;
    }

    // PROVIDED MAIN
    std::cout << "42 PROVIDED MAIN" << std::endl;

    Array<int>
        numbers(MAX_VAL);
    int *mirror = new int[MAX_VAL];
    srand(time(NULL));
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
        Array<int> tmp = numbers;
        Array<int> test(tmp);

        std::cout << "Outputting tmp:" << std::endl;
        std::cout << tmp << std::endl;

        std::cout << "Outputting test:" << std::endl;
        std::cout << test << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete[] mirror; //
    return 0;
    return (0);
}