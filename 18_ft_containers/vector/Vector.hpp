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
        // Fill constructors
        vector(size_type count) : _size(count), _capacity(count), _isEmpty(false)
        {
            this->_alloc = *(new allocator_type);
            this->_array = this->_alloc.allocate(count);
            for (size_type i = 0; i < count; ++i)
                this->_alloc.construct((this->_array + i));
            this->_maxSize = this->_alloc.max_size();
        }
        vector(size_type count, const T &value) : _size(count), _capacity(count), _isEmpty(false)
        {
            this->_alloc = *(new allocator_type);
            this->_array = this->_alloc.allocate(count);
            for (size_type i = 0; i < count; ++i)
                this->_alloc.construct((this->_array + i), value);

            this->_maxSize = this->_alloc.max_size();
        }
        // Range constructor
        // Copy constructor
        // Destructor
        ~vector()
        {
            for (size_type i = 0; i < this->_size; ++i)
                this->_array[i] = 0;
            this->_alloc.destroy(this->_array);
        }

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
         * Capacity
         */
        void push_back(const T &value)
        {
            this->_array[this->_size] = value;
        }

        /*
         * Allocator
         */
        allocator_type get_allocator() const
        {
            return this->_alloc;
        }

        /* ----------------------------------
         * Access
         * ---------------------------------- */
        reference operator[](size_type pos)
        {
            return *(this->_array + pos);
        }
        // const_reference operator[](size_type pos) const
        // {
        //     return *(this->_array + pos);
        // }

        T *data()
        {
            return this->_array;
        }
        const T *data() const
        {
            return const_cast<T *>(this->_array);
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
