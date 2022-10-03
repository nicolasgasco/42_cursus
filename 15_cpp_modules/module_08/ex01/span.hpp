#pragma once
#ifndef __SPAN_H__
#define __SPAN_H__

#include <iostream>
#include <iterator>
#include <vector>
#include <limits>
#include <cstdlib>
#include <numeric>
#include <algorithm>

void absoluteValue(int &n)
{
    n = abs(n);
}
class Span
{

public:
    Span(unsigned int N) : size(N)
    {
        std::cout << "Span parameter constructor called (" << N << ")" << std::endl;
    }

    Span(Span const &src)
    {
        *this = src;
        std::cout << "Span copy constructor called" << &src << std::endl;
    }

    ~Span(void)
    {
        std::cout << "Span destructor called" << std::endl;
    }

    Span &operator=(const Span &src)
    {
        // Copy array
        size = src.size;
        std::cout << "Span assignment operator" << &src << std::endl;
        return *this;
    }

    void addNumber(int value)
    {
        if (ints.size() == size)
            throw Span::ListAlreadyFull();
        ints.push_back(value);
    }

    unsigned int shortestSpan(void)
    {
        if (this->ints.size() <= 1)
            throw Span::NoSpanToFind();

        std::vector<int>::const_iterator start = this->ints.begin();
        std::vector<int>::const_iterator end = this->ints.end();

        std::vector<int> differences(this->size);
        std::vector<int>::iterator differencesStart = differences.begin();

        std::adjacent_difference(start, end, differencesStart);

        std::for_each(
            differences.begin(), differences.end(), absoluteValue);

        return (*(std::min_element(differences.begin(), differences.end())));
    }

    unsigned int longestSpan(void) const
    {
        if (this->ints.size() <= 1)
            throw Span::NoSpanToFind();

        std::vector<int>::const_iterator start = this->ints.begin();
        std::vector<int>::const_iterator end = this->ints.end();

        std::vector<int> differences(this->size);
        std::vector<int>::iterator differencesStart = differences.begin();

        std::adjacent_difference(start, end, differencesStart);

        std::for_each(
            differences.begin(), differences.end(), absoluteValue);

        return (*(std::max_element(differences.begin(), differences.end())));
    }

private:
    std::vector<int> ints;
    unsigned int size;

    Span(void) : size(0)
    {
        std::cout << "Span default constructor called" << std::endl;
    }

    class ListAlreadyFull : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return ("List is already full");
        }
    };

    class NoSpanToFind : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return ("There is no Span to find");
        }
    };
};

#endif