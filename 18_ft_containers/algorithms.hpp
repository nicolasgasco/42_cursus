#pragma once

#include <iostream>

namespace ft
{
    template <class T>
    void swap(T &a, T &b)
    {
        T temp(a);
        a = b;
        b = temp;
    }

    template <class InputIterator1, class InputIterator2>
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
    {
        if (first1 && last1 && first2)
        {
        }
    }

    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
    {
        if (first1 && last1 && first2 && pred)
        {
        }
    }

    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
    {
        if (first1 && last1 && first2 && last2)
        {
        }
    }

    template <class InputIterator1, class InputIterator2, class Compare>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
    {
        if (first1 && last1 && first2 && last2 && comp)
        {
        }
    }
}
