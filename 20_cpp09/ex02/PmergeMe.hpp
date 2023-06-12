#pragma once
#ifndef __PmergeMe_H__
#define __PmergeMe_H__

#include <iostream>
#include <sys/time.h>

#define MAX_ITEMS 30

#include <vector>
#include <list>

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
    void output_sorted_result();

private:
    std::vector<unsigned int> _unsorted_vec;
    std::vector<unsigned int> _sorted_vec;
    double _elapsed_time_vec;

    std::list<unsigned int> _unsorted_list;
    std::list<unsigned int> _sorted_list;
    double _elapsed_time_list;

    std::vector<unsigned int> _split_numbers_vec(std::vector<unsigned int> &numbers_vec);
    std::list<unsigned int> _split_numbers_list(std::list<unsigned int> &numbers_list);

    void _insertion_sort_vec(std::vector<unsigned int> &numbers_vec);
    void _insertion_sort_list(std::list<unsigned int> &numbers_list);

    void _sort_numbers_vec();
    void _sort_numbers_list();

    void _output_formatted_vector(std::vector<unsigned int> const &numbers);
    void _output_formatted_list(std::list<unsigned int> const &numbers);
};

#endif