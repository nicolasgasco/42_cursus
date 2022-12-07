#pragma once

#include <iostream>

namespace ft
{
    template <class T1, class T2>
    struct pair
    {
    public:
        typedef T1 first_type;
        typedef T2 second_type;

        pair()
        {
            this->_first = first_type();
            this->_second = second_type();
        }

        template <class U, class V>
        pair(const pair<U, V> &pr)
        {
            this->_first = first_type(pr._first);
            this->_second = second_type(pr._second);
        }

        pair(const first_type &a, const second_type &b)
        {
            this->_first = first_type(a);
            this->_second = second_type(b);
        }

        pair &operator=(const pair &pr)
        {
            this->_first = pr._first;
            this->_second = pr._second;
        }

    private:
        first_type _first;
        second_type _second;
    };

    template <class T1, class T2>
    pair<T1, T2> make_pair(T1 x, T2 y)
    {
        return (pair<T1, T2>(x, y));
    }

    template <class T1, class T2>
    bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return lhs.first == rhs.first && lhs.second == rhs.second;
    }

    template <class T1, class T2>
    bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return !(lhs == rhs);
    }

    template <class T1, class T2>
    bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
    }

    template <class T1, class T2>
    bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return !(rhs < lhs);
    }

    template <class T1, class T2>
    bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return rhs < lhs;
    }

    template <class T1, class T2>
    bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    {
        return !(lhs < rhs);
    }

}
