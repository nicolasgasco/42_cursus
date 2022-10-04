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

class Span
{

public:
    Span(unsigned int N);
    Span(Span const &src);

    ~Span(void);

    Span &operator=(const Span &src);

    void addNumber(int value);

    unsigned int shortestSpan(void);
    unsigned int longestSpan(void) const;

    void addRandomNumbers(unsigned int quantity);

    void outputVector(void) const;

private:
    std::vector<int> ints;
    unsigned int size;

    Span(void);

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

std::ostream &operator<<(std::ostream &os, Span const &std);

#endif