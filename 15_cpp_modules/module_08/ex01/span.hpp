#pragma once
#ifndef __SPAN_H__
#define __SPAN_H__

#include <iostream>
#include <iterator>
#include <vector>
#include <limits>

class Span
{

public:
    Span(unsigned int N) : size(N)
    {
        std::cout << "Span parameter constructor called (" << N << ")" << std::endl;
    }
    Span(Span const &src)
    {
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
        std::cout << value << " was added to the vector" << std::endl;
    }

    unsigned int shortestSpan(void) const
    {
        unsigned int size = ints.size();
        if (size <= 1)
            throw Span::NoSpanToFind();

        // unsigned int result = std::numeric_limits<int>::max();

        // for (int i = 0; i < (static_cast<int>(size) - 1); i++)
        //     for (int j = i + 1; j < static_cast<int>(size); j++)
        //     {
        //         std::list<int>::const_iterator it = ints.begin();
        //         std::list<int>::const_iterator firstValueIt = std::advance(it, i);
        //         std::cout
        //             << "mierda " << *firstValueIt << std::endl;
        //         // unsigned diff = std::abs(*(std::advance(it, i)) - *(std::advance(it, j)));
        //         // if (diff < result)
        //         //     result = diff;
        //     }
        return (10);
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