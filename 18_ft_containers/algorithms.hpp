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
        for (InputIterator1 it = first1; it != last1; ++it)
        {
            if (*it != *first2)
                return false;
            ++first2;
        }
        return true;
    }

    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
    {
        for (InputIterator1 it = first1; it != last1; ++it)
        {
            if (!pred(*it, *first2))
                return false;
            ++first2;
        }
        return true;
    }

}
