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

        first_type first;
        second_type second;

        pair()
        {
            this->first = first_type();
            this->second = second_type();
        }

        template <class U, class V>
        pair(const ft::pair<U, V> &pr)
        {
            this->first = first_type(pr.first);
            this->second = second_type(pr.second);
        }

        // Not required but useful
        template <class U, class V>
        pair(const std::pair<U, V> &pr)
        {
            this->first = first_type(pr.first);
            this->second = second_type(pr.second);
        }

        pair(const first_type &a, const second_type &b)
        {
            this->first = first_type(a);
            this->second = second_type(b);
        }

        pair &operator=(const pair &pr)
        {
            this->first = pr.first;
            this->second = pr.second;
        }
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
