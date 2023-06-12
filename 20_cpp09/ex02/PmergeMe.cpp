#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::store_numbers(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        int value = std::atoi(argv[i]);
        this->_numbers_vec.push_back(value);
    }
}

void PmergeMe::sort_numbers()
{
    std::vector<unsigned int> tmp = this->_numbers_vec;
    std::cout << "tmp vec size: " << this->_numbers_vec.size() << std::endl;
    this->_split_numbers(tmp);
}

void PmergeMe::_split_numbers(std::vector<unsigned int> &numbers_vec)
{
    std::vector<unsigned int> tmp = numbers_vec;
    if (tmp.size() == 2)
    {
        std::cout << "Left with 2 elements: ";
    }
    for (std::vector<unsigned int>::iterator it = tmp.begin(); it != tmp.end(); it++)
    {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;

    if (tmp.size() == 2)
    {
        if (tmp.front() > tmp.back())
        {
            std::cout << "Swapping " << tmp.front() << " and " << tmp.back() << std::endl;
            std::swap(tmp.front(), tmp.back());
        }
    }
    else
    {
        std::vector<unsigned int> left(tmp.begin(), tmp.begin() + tmp.size() / 2);
        std::vector<unsigned int> right(tmp.begin() + tmp.size() / 2, tmp.end());

        this->_split_numbers(left);
        this->_split_numbers(right);
    }
}
