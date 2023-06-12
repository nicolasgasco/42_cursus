#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::store_numbers(int argc, char *argv[])
{
    this->_unsorted_vec.reserve(argc - 1);
    this->_sorted_vec.reserve(argc - 1);
    for (int i = 1; i < argc; i++)
    {
        int value = std::atoi(argv[i]);
        this->_unsorted_vec.push_back(value);
        this->_sorted_vec.push_back(value);
    }
}

void PmergeMe::sort_numbers()
{
    struct timeval start, stop;

    gettimeofday(&start, NULL);

    this->_sorted_vec = this->_split_numbers(this->_unsorted_vec);
    this->_insertion_sort(this->_sorted_vec);

    gettimeofday(&stop, NULL);

    this->_elapsed_time_vec = (stop.tv_sec - start.tv_sec) * 1000.0;    // sec to ms
    this->_elapsed_time_vec += (stop.tv_usec - start.tv_usec) / 1000.0; // us to ms

    this->_output_result();
}

std::vector<unsigned int> PmergeMe::_split_numbers(std::vector<unsigned int> &numbers_vec)
{
    if (numbers_vec.size() <= 2)
    {
        if (numbers_vec.front() > numbers_vec.back())
            std::swap(numbers_vec.front(), numbers_vec.back());

        return numbers_vec;
    }

    std::vector<unsigned int> numbers_vec_left(numbers_vec.begin(), numbers_vec.begin() + numbers_vec.size() / 2);
    std::vector<unsigned int> left = this->_split_numbers(numbers_vec_left);
    this->_insertion_sort(left);

    std::vector<unsigned int> numbers_vec_right(numbers_vec.begin() + numbers_vec.size() / 2, numbers_vec.end());
    std::vector<unsigned int> right = this->_split_numbers(numbers_vec_right);
    this->_insertion_sort(right);

    std::vector<unsigned int> result;
    result.reserve(left.size() + right.size());
    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), right.begin(), right.end());
    return result;
}

void PmergeMe::_insertion_sort(std::vector<unsigned int> &numbers_vec)
{
    if (numbers_vec.size() <= 2)
        return;

    while (true)
    {
        bool is_sorted = true;
        for (std::vector<unsigned int>::iterator it = numbers_vec.begin(); it != numbers_vec.end() - 1; it++)
        {
            if (*it > *(it + 1))
            {
                is_sorted = false;
                bool is_found_it2 = false;
                for (std::vector<unsigned int>::iterator it2 = numbers_vec.begin(); it2 != numbers_vec.end(); it2++)
                {
                    if (*it < *it2)
                    {
                        is_found_it2 = true;
                        unsigned int value = *it;
                        numbers_vec.erase(it);
                        numbers_vec.insert(it2, value);
                        break;
                    }
                }
                if (!is_found_it2)
                {
                    unsigned int value = *it;
                    numbers_vec.erase(it);
                    numbers_vec.push_back(value);
                }
                break;
            }
        }
        if (is_sorted)
            break;
    }
}

void PmergeMe::_output_result()
{
    std::cout << "Before: ";
    this->_output_formatted_vector(this->_unsorted_vec);

    std::cout << std::endl;
    std::cout << "After: ";
    this->_output_formatted_vector(this->_sorted_vec);

    std::cout << std::endl;
    std::cout << "Time to process a range of " << this->_unsorted_vec.size() << " elements with std::vector: " << this->_elapsed_time_vec << " ms" << std::endl;
}

void PmergeMe::_output_formatted_vector(std::vector<unsigned int> const &numbers)
{
    for (size_t i = 0; i < numbers.size(); i++)
    {
        if (i == MAX_ITEMS)
        {
            std::cout << "[...]";
            break;
        }
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
}