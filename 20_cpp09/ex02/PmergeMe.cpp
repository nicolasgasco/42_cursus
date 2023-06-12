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
    std::vector<unsigned int> result = this->_split_numbers(tmp);
    this->output_vector(result);
}

std::vector<unsigned int> PmergeMe::_split_numbers(std::vector<unsigned int> &numbers_vec)
{
    std::cout << GREEN << "Down (start of function): ";
    this->output_vector(numbers_vec);

    if (numbers_vec.size() == 2)
    {
        if (numbers_vec.front() > numbers_vec.back())
        {
            std::cout << "Down: Swapping " << numbers_vec.front() << " and " << numbers_vec.back() << std::endl;
            std::swap(numbers_vec.front(), numbers_vec.back());
        }

        return numbers_vec;
    }

    std::vector<unsigned int> numbers_vec_left(numbers_vec.begin(), numbers_vec.begin() + numbers_vec.size() / 2);
    std::vector<unsigned int> left = this->_split_numbers(numbers_vec_left);
    std::cout << YELLOW << "Up left: ";
    this->output_vector(left);

    std::vector<unsigned int> numbers_vec_right(numbers_vec.begin() + numbers_vec.size() / 2, numbers_vec.end());
    std::vector<unsigned int> right = this->_split_numbers(numbers_vec_right);
    std::cout << YELLOW << "Up right: ";
    this->output_vector(right);

    std::vector<unsigned int> result;
    result.reserve(left.size() + right.size());
    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), right.begin(), right.end());
    return result;
}

void PmergeMe::output_vector(std::vector<unsigned int> vector)
{
    for (std::vector<unsigned int>::iterator it = vector.begin(); it != vector.end(); it++)
    {
        std::cout << *it << ", ";
    }
    std::cout << NC << std::endl;
}