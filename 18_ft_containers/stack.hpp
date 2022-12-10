#pragma once

#include "algorithms.hpp"
#include "enable_if.hpp"
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"
#include "vector.hpp"
#include <iostream>

namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack
    {
    public:
        typedef Container container_type;
        typedef typename container_type::value_type value_type;
        typedef typename container_type::size_type size_type;

    private:
        container_type c;

    public:
        /* ----------------------------------
         * LIFECYCLE
         * ---------------------------------- */
        explicit stack(const container_type &ctnr = container_type())
        {
            c = ctnr;
        }

        stack &operator=(const stack &other)
        {
            c = other.c;
            return *this;
        }

        ~stack()
        {
        }

        /* ----------------------------------
         * ACCESS
         * ---------------------------------- */
        value_type &top()
        {
            return c.back();
        }
        const value_type &top() const
        {
            return c.back();
        }

        /* ----------------------------------
         * CAPACITY
         * ---------------------------------- */
        bool empty() const
        {
            return c.empty();
        }

        size_type size() const
        {
            return c.size();
        }

        /* ----------------------------------
         * MODIFIERS
         * ---------------------------------- */
        void push(const value_type &val)
        {
            this->c.push_back(value_type(val));
        }

        void pop()
        {
            this->c.pop_back();
        }

        /* ----------------------------------
         * RELATIONAL OPERATORS PROTOTYPES
         * ---------------------------------- */
        template <class T1, class Container1>
        friend bool operator==(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs);

        template <class T1, class Container1>
        friend bool operator!=(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs);

        template <class T1, class Container1>
        friend bool operator<(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs);

        template <class T1, class Container1>
        friend bool operator<=(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs);

        template <class T1, class Container1>
        friend bool operator>(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs);

        template <class T1, class Container1>
        friend bool operator>=(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs);
    };

    /* ----------------------------------
     * RELATIONAL OPERATORS
     * ---------------------------------- */
    template <class T, class Container>
    bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
    {
        return lhs.c == rhs.c;
    }

    template <class T, class Container>
    bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
    {
        return lhs.c != rhs.c;
    }

    template <class T, class Container>
    bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
    {
        return lhs.c < rhs.c;
    }

    template <class T, class Container>
    bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
    {
        return lhs.c <= rhs.c;
    }

    template <class T, class Container>
    bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
    {
        return lhs.c > rhs.c;
    }

    template <class T, class Container>
    bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
    {
        return lhs.c >= rhs.c;
    }
}
