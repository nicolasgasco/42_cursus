#pragma once
#ifndef __PmergeMe_H__
#define __PmergeMe_H__

#include <iostream>
#include <sys/time.h>

#include <vector>
#include <list>

#define MAX_SHOW_ITEMS 30

class PmergeMe
{

public:
    PmergeMe();
    PmergeMe(PmergeMe const &src);

    ~PmergeMe();

    PmergeMe &operator=(const PmergeMe &src);

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
