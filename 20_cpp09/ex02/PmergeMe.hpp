#pragma once
#ifndef __PmergeMe_H__
#define __PmergeMe_H__

#include <iostream>
#include <sys/time.h>

#define MAX_ITEMS 30

#include <vector>

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

private:
    std::vector<unsigned int> _unsorted_vec;
    std::vector<unsigned int> _sorted_vec;
    double _elapsed_time_vec;

    std::vector<unsigned int> _split_numbers(std::vector<unsigned int> &numbers_vec);
    void _insertion_sort(std::vector<unsigned int> &numbers_vec);

    void _output_result();
    void _output_formatted_vector(std::vector<unsigned int> const &numbers);
};

#endif