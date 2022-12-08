#pragma once

#include "algorithms.hpp"
#include "enable_if.hpp"
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"
#include "vector.hpp"
#include <iostream>

namespace ft
{
    template <class T, class Container = std::vector<T> >
    class stack
    {
    public:
        typedef Container container_type;
        typedef typename container_type::value_type value_type;
        typedef typename container_type::size_type size_type;

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

    private:
        container_type c;
    };

}
