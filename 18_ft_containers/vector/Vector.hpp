#pragma once

#include <iostream>

namespace ft
{
    template <class T, class Allocator = std::allocator<T> >
    class vector
    {
    public:
        /*
         * MEMBER TYPES
         */
        typedef T value_type;
        typedef Allocator allocator_type;
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
        vector(const allocator_type &alloc = allocator_type()) : _size(0), _capacity(0), _isEmpty(true)
        {
            this->_alloc = alloc;
            this->_data = this->_alloc.allocate(0);

            this->_maxSize = this->_alloc.max_size();
        }

        // Fill constructors
        vector(size_type count, const value_type &value = value_type(), const allocator_type &alloc = allocator_type()) : _size(count), _capacity(count), _isEmpty(false)
        {
            this->_alloc = alloc;
            this->_data = this->_alloc.allocate(count);
            for (size_type i = 0; i < count; ++i)
                this->_alloc.construct((this->_data + i), value);

            this->_maxSize = this->_alloc.max_size();
        }

        // Range constructor
        // template <class InputIterator>
        // vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type());

        // Copy constructor
        // vector(const vector &x) {}

        // Destructor
        ~vector()
        {
            this->destroyAllocatedData();
        }

        /* ----------------------------------
         * Member functions
         * ---------------------------------- */

        /*
         * Capacity
         */
        bool empty() const
        {
            return this->_isEmpty;
        }

        size_type size() const
        {
            return this->_size;
        }

        size_type max_size() const
        {
            return _maxSize;
        }

        size_type capacity() const
        {
            // pow(2, ceil(log(i) / log(2)))
            return this->_capacity;
        }

        void reserve(size_type new_cap)
        {
            if (new_cap > this->_maxSize || new_cap < 0)
            {
                throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
            }
            if (new_cap <= this->_capacity)
            {
                return;
            }
            // allocate new space, copy and substitute
            value_type *tmp = this->_alloc.allocate(new_cap);
            this->_capacity = new_cap;
            for (size_type i = 0; i < this->_size; ++i)
                this->_alloc.construct((tmp + i), this->_data[i]);
            this->destroyAllocatedData();
            this->_data = tmp;
        }

        /*
         * Modifiers
         */
        // void push_back(const T &value)
        // {
        //     this->_data[this->_size] = value;
        // }

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
        reference at(size_type pos)
        {
            if (pos < 0 || pos > (this->_size - 1))
                throw std::out_of_range("vector");
            return *(this->_data + pos);
        }
        const_reference at(size_type pos) const
        {
            if (pos < 0 || pos > (this->_size - 1))
                throw std::out_of_range("vector");
            return *(this->_data + pos);
        }

        reference operator[](size_type pos)
        {
            return *(this->_data + pos);
        }
        const_reference operator[](size_type pos) const
        {
            return *(this->_data + pos);
        }

        reference front()
        {
            return *(this->_data);
        }
        const_reference front() const
        {
            return *(this->_data);
        }

        reference back()
        {
            return *(this->_data + (this->_size - 1));
        }
        const_reference back() const
        {
            return *(this->_data + (this->_size - 1));
        }

        value_type *data()
        {
            return this->_data;
        }
        const value_type *data() const
        {
            return const_cast<value_type *>(this->_data);
        }

    private:
        allocator_type _alloc;
        value_type *_data;

        size_type _size;
        size_type _capacity;
        bool _isEmpty;
        size_type _maxSize;

        void destroyAllocatedData()
        {
            for (size_type i = 0; i < this->_size; ++i)
                this->_data[i] = 0;
            this->_alloc.destroy(this->_data);
        }
    };
}
