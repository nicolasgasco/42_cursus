#include <iostream>
#include "PmergeMe.hpp"

bool is_input_valid(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        for (unsigned int j = 0; j < strlen(argv[i]); j++)
        {
            if (!std::isdigit(argv[i][j]))
                return false;
        }

        int value = std::atoi(argv[i]);
        if (value < 0)
            return false;
    }
    return true;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Please provide an argument" << std::endl;
        return 1;
    }
    else if (argc == 2)
    {
        std::cout << "Provide more than one argument" << std::endl;
        return 1;
    }

    if (!is_input_valid(argc, argv))
    {
        std::cout << "Invalid input" << std::endl;
        return 1;
    }

    PmergeMe pmergeMe;
    pmergeMe.store_numbers(argc, argv);
    pmergeMe.output_sorted_result();

    // std::cout << std::endl;
    // PmergeMe pmergeMe2(pmergeMe);
    // pmergeMe2.output_sorted_result();

    return 0;
}
