#pragma once

#include <iostream>

namespace ft
{
    template <class T>
    class vector
    {
    public:
        /*
         * MEMBER TYPES
         */
        typedef T value_type;
        typedef std::allocator<T> allocator_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        // typedef implementation - defined iterator;
        // typedef implementation - defined const_iterator;
        typedef typename allocator_type::size_type size_type;
        // typedef typename allocator_type::difference_type difference_type;
        typedef typename allocator_type::pointer pointer;
        // typedef typename allocator_type::const_pointer const_pointer;
        // typedef std::reverse_iterator<iterator> reverse_iterator;
        // typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

        /* ----------------------------------
         * LIFECYCLE
         * ---------------------------------- */
        // Empty constructor
        vector() : _size(0), _capacity(0), _isEmpty(true)
        {
            this->_alloc = *(new allocator_type);
            this->_array = this->_alloc.allocate(0);

            this->_maxSize = this->_alloc.max_size();
        }
        // Fill constructor
        // Range constructor
        // Copy constructor

        /* ----------------------------------
         * Member functions
         * ---------------------------------- */

        /*
         * Capacity
         */
        size_type size() const
        {
            return this->_size;
        }

        size_type capacity() const
        {
            // pow(2, ceil(log(i) / log(2)))
            return this->_capacity;
        }

        bool empty() const
        {
            return this->_isEmpty;
        }

        size_type max_size() const
        {
            return _maxSize;
        }

        /*
         * Allocator
         */
        allocator_type get_allocator() const
        {
            return this->_alloc;
        }

    private:
        allocator_type _alloc;
        T *_array;

        size_type _size;
        size_type _capacity;
        bool _isEmpty;
        size_type _maxSize;
    };
}
