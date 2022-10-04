#pragma once
#ifndef __SPAN_H__
#define __SPAN_H__

#include <iostream>
#include <iterator>
#include <vector>
#include <numeric>
#include <algorithm>

#define PURPLE "\033[0;35m"
#define NOCOL "\033[0m"

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
};

std::ostream &operator<<(std::ostream &os, Span const &std);

#endif