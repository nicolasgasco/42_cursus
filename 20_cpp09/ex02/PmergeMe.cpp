#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _elapsed_time_vec(0), _elapsed_time_list(0)
{
}

PmergeMe::PmergeMe(PmergeMe const &src)
{
    *this = src;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
    this->_unsorted_vec = src._unsorted_vec;
    this->_sorted_vec = src._sorted_vec;
    this->_elapsed_time_vec = src._elapsed_time_vec;

    this->_unsorted_list = src._unsorted_list;
    this->_sorted_list = src._sorted_list;
    this->_elapsed_time_list = src._elapsed_time_list;
    return *this;
}

void PmergeMe::store_numbers(int argc, char *argv[])
{
    this->_unsorted_vec.reserve(argc - 1);
    for (int i = 1; i < argc; i++)
    {
        int value = std::atoi(argv[i]);
        this->_unsorted_vec.push_back(value);

        this->_unsorted_list.push_back(value);
    }
    this->_sorted_vec = this->_unsorted_vec;
    this->_sorted_list = this->_unsorted_list;

    this->_sort_numbers_vec();
    this->_sort_numbers_list();
}

void PmergeMe::output_sorted_result()
{
    std::cout << "Before: ";
    this->_output_formatted_vector(this->_unsorted_vec);

    std::cout << std::endl;
    std::cout << "After: ";
    this->_output_formatted_list(this->_sorted_list);

    std::cout << std::endl;
    std::cout << "Time to process a range of " << this->_unsorted_vec.size() << " elements with std::vector: " << this->_elapsed_time_vec << " ms" << std::endl;
    std::cout << "Time to process a range of " << this->_unsorted_vec.size() << " elements with std::list: " << this->_elapsed_time_list << " ms" << std::endl;
}

void PmergeMe::_sort_numbers_vec()
{
    struct timeval start_vec, stop_vec;

    gettimeofday(&start_vec, NULL);
    this->_sorted_vec = this->_split_numbers_vec(this->_sorted_vec);
    this->_insertion_sort_vec(this->_sorted_vec);
    gettimeofday(&stop_vec, NULL);

    this->_elapsed_time_vec = (stop_vec.tv_sec - start_vec.tv_sec) * 1000.0; // sec to ms
    this->_elapsed_time_vec += (stop_vec.tv_usec - start_vec.tv_usec) / 1000.0;
}

void PmergeMe::_sort_numbers_list()
{
    struct timeval start_list, stop_list;

    gettimeofday(&start_list, NULL);
    this->_sorted_list = this->_split_numbers_list(this->_sorted_list);
    this->_insertion_sort_list(this->_sorted_list);
    gettimeofday(&stop_list, NULL);

    this->_elapsed_time_list = (stop_list.tv_sec - start_list.tv_sec) * 1000.0; // sec to ms
    this->_elapsed_time_list += (stop_list.tv_usec - start_list.tv_usec) / 1000.0;
}

std::vector<unsigned int> PmergeMe::_split_numbers_vec(std::vector<unsigned int> &numbers_vec)
{
    if (numbers_vec.size() <= 2)
    {
        if (numbers_vec.front() > numbers_vec.back())
            std::swap(numbers_vec.front(), numbers_vec.back());

        return numbers_vec;
    }

    std::vector<unsigned int> numbers_vec_left(numbers_vec.begin(), numbers_vec.begin() + numbers_vec.size() / 2);
    std::vector<unsigned int> left = this->_split_numbers_vec(numbers_vec_left);
    this->_insertion_sort_vec(left);

    std::vector<unsigned int> numbers_vec_right(numbers_vec.begin() + numbers_vec.size() / 2, numbers_vec.end());
    std::vector<unsigned int> right = this->_split_numbers_vec(numbers_vec_right);
    this->_insertion_sort_vec(right);

    std::vector<unsigned int> result;
    result.reserve(left.size() + right.size());
    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), right.begin(), right.end());
    return result;
}

std::list<unsigned int> PmergeMe::_split_numbers_list(std::list<unsigned int> &numbers_list)
{
    if (numbers_list.size() <= 2)
    {
        if (numbers_list.front() > numbers_list.back())
            std::swap(numbers_list.front(), numbers_list.back());

        return numbers_list;
    }

    std::list<unsigned int> numbers_list_left;
    std::list<unsigned int> numbers_list_right;

    unsigned int i = 0;
    for (std::list<unsigned int>::iterator it = numbers_list.begin(); it != numbers_list.end(); it++)
    {
        if (i < numbers_list.size() / 2)
            numbers_list_left.push_back(*it);
        else
            numbers_list_right.push_back(*it);
        i++;
    }
    std::list<unsigned int> left = this->_split_numbers_list(numbers_list_left);
    this->_insertion_sort_list(left);
    std::list<unsigned int> right = this->_split_numbers_list(numbers_list_right);
    this->_insertion_sort_list(right);

    std::list<unsigned int> result;
    result.splice(result.end(), left);
    result.splice(result.end(), right);

    return result;
}

void PmergeMe::_insertion_sort_vec(std::vector<unsigned int> &numbers_vec)
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

void PmergeMe::_insertion_sort_list(std::list<unsigned int> &numbers_list)
{
    if (numbers_list.size() <= 2)
        return;

    while (true)
    {
        bool is_sorted = true;
        for (std::list<unsigned int>::iterator it = numbers_list.begin(), second_to_last = std::prev(numbers_list.end()); it != second_to_last; it++)
        {
            std::list<unsigned int>::iterator next_it = std::next(it);
            if (*it > *(next_it))
            {
                is_sorted = false;
                bool is_found_it2 = false;
                for (std::list<unsigned int>::iterator it2 = numbers_list.begin(); it2 != numbers_list.end(); it2++)
                {
                    if (*it < *it2)
                    {
                        is_found_it2 = true;
                        unsigned int value = *it;
                        numbers_list.erase(it);
                        numbers_list.insert(it2, value);
                        break;
                    }
                }
                if (!is_found_it2)
                {
                    unsigned int value = *it;
                    numbers_list.erase(it);
                    numbers_list.push_back(value);
                }
                break;
            }
        }
        if (is_sorted)
            break;
    }
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

void PmergeMe::_output_formatted_list(std::list<unsigned int> const &numbers)
{
    unsigned int i = 0;
    for (std::list<unsigned int>::const_iterator it = numbers.begin(); it != numbers.end(); it++)
    {
        if (i == MAX_ITEMS)
        {
            std::cout << "[...]";
            break;
        }
        std::cout << *it << " ";
        i++;
    }
    std::cout << std::endl;
}