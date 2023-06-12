#pragma once
#ifndef __PmergeMe_H__
#define __PmergeMe_H__

#include <iostream>

class PmergeMe
{

public:
    PmergeMe();

    ~PmergeMe();

    void store_numbers(int argc, char *argv[]);
    void sort_numbers();

private:
    std::vector<unsigned int> _numbers_vec;

    void _split_numbers(std::vector<unsigned int> &numbers_vec);
};

#endif