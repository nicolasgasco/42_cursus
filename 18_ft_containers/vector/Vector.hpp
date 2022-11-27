#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include <iostream>

namespace ft
{
    template <class T>
    class vector
    {
    public:
        /*
         * LIFECYCLE
         */
        vector() : _size(0)
        {
        }

        /*
         * MEMBER TYPES
         */
        // T value_type;
        typedef std::allocator<T> allocator_type;
        // allocator_type::reference reference;
        // allocator_type::const_reference const_reference;
        typedef typename allocator_type::size_type size_type;
        // allocator_type::difference_type difference_type;
        // allocator_type::pointer pointer;
        // allocator_type::const_pointer const_pointer;
        // std::reverse_iterator<iterator> reverse_iterator;
        // std::reverse_iterator<const_iterator> const_reverse_iterator;

        /*
         * MEMBER FUNCTIONS
         */

        /*
         * Capacity
         */
        size_type size() const
        {
            return this->_size;
        }

    private:
        T *_array;
        std::size_t _size;
    };
}

#endif
