#pragma once
#ifndef __PmergeMe_H__
#define __PmergeMe_H__

#include <iostream>

// Remove after testing
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define NC "\033[0m"

class PmergeMe
{

public:
    PmergeMe();

    ~PmergeMe();

    void store_numbers(int argc, char *argv[]);
    void sort_numbers();

    // Remove after testing
    void output_vector(std::vector<unsigned int> vector);

private:
    std::vector<unsigned int> _numbers_vec;

    std::vector<unsigned int> _split_numbers(std::vector<unsigned int> &numbers_vec);
};

#endif