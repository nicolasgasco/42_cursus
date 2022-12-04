#pragma once

#include "iterator_traits.hpp"
#include "algorithms.hpp"

#include <iostream>

namespace ft
{
    template <class T, class Allocator = std::allocator<T>>
    class vector
    {
    public:
        /*
         * MEMBER TYPES
         */
        typedef T value_type;
        typedef Allocator allocator_type;
        typedef typename allocator_type::size_type size_type;
        typedef typename allocator_type::difference_type difference_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef typename ft::iterator_traits<pointer>::pointer iterator;
        typedef typename ft::iterator_traits<const_pointer>::pointer const_iterator;
        // typedef std::reverse_iterator<iterator> reverse_iterator;
        // typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

        /* ----------------------------------
         * LIFECYCLE
         * ---------------------------------- */
        // Empty constructor
        vector(const allocator_type &alloc = allocator_type()) : _size(0), _capacity(0)
        {
            this->_alloc = alloc;
            this->_data = this->_alloc.allocate(0);

            this->_maxSize = this->_alloc.max_size();
        }

        // Fill constructors
        vector(size_type count, const value_type &value = value_type(), const allocator_type &alloc = allocator_type()) : _size(count), _capacity(count)
        {
            this->_alloc = alloc;
            this->_data = this->_alloc.allocate(count);
            for (size_type i = 0; i < count; ++i)
                this->_alloc.construct((this->_data + i), value);

            this->_maxSize = this->_alloc.max_size();
        }

        // Range constructor
        vector(iterator first, iterator last, const allocator_type &alloc = allocator_type())
        {
            size_type rangeSize = last - first;
            this->_alloc = alloc;

            this->_data = this->_alloc.allocate(rangeSize);
            this->_capacity = rangeSize;
            for (size_type i = 0; i < rangeSize; ++i, ++first)
                this->_alloc.construct((this->_data + i), *first);
            this->_size = rangeSize;

            this->_maxSize = this->_alloc.max_size();
        }

        // Copy constructor
        vector(const vector &x)
        {
            this->_alloc = x.get_allocator();
            this->_size = 0;
            this->_capacity = 0;
            *this = x;
        }

        vector &operator=(const vector &other)
        {
            if (this->size())
            {
                for (size_type i = 0; i < this->_size; ++i)
                    this->_data[i] = 0;
                if (this->_data)
                    this->_alloc.destroy(this->_data);
            }
            this->_maxSize = other.max_size();
            if (this->_capacity < other.size())
            {
                this->reserve(other.size());
                this->_capacity = other.size();
            }
            for (size_type i = 0; i < other.size(); ++i)
                this->_alloc.construct((this->_data + i), other[i]);
            this->_size = other.size();
            return *this;
        }

        // Destructor
        ~vector()
        {
            this->destroyAllocatedData();
        }

        /* ----------------------------------
         * Iterators
         * ---------------------------------- */
        iterator begin()
        {
            return iterator(this->_data);
        }
        const_iterator begin() const
        {
            return iterator(this->_data);
        }

        iterator end()
        {
            return iterator(this->_data + this->_size);
        }
        const_iterator end() const
        {
            return iterator(this->_data + this->_size);
        }

        /* ----------------------------------
         * Member functions
         * ---------------------------------- */

        /*
         * Capacity
         */
        bool empty() const
        {
            return (this->_size == 0) ? true : false;
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
            return this->_capacity;
        }

        void reserve(size_type new_cap)
        {
            if (new_cap > this->_maxSize || new_cap < 0)
                throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
            if (new_cap <= this->_capacity)
                return;
            this->allocateBiggerDataCopy(new_cap);
            this->_capacity = new_cap;
        }

        /*
         * Modifiers
         */
        void push_back(const value_type &value)
        {
            size_type newSize = this->_size + 1;
            if (newSize > this->_capacity)
                this->increaseCapacity();
            this->_data[this->_size] = value;
            this->_size++;
        }

        void pop_back()
        {
            this->_alloc.destroy(this->_data + (this->_size - 1));
            this->_size--;
        }

        void resize(size_type count, value_type value = value_type())
        {
            if (count < 0 || count > this->_maxSize)
                throw std::length_error("vector");
            if (count < this->_size)
            {
                for (size_type i = count; i < this->_size; ++i)
                    this->_alloc.destroy(this->_data + i);
                this->_size = count;
                return;
            }
            if (count > this->_size)
            {
                if (count > this->_capacity)
                {
                    size_type newCapacity = (count > (this->_capacity * 2)) ? count : this->_capacity * 2;
                    this->allocateBiggerDataCopy(newCapacity);
                    this->_capacity = newCapacity;
                }
                for (size_type i = this->_size; i < count; ++i)
                    this->_alloc.construct(this->_data + i, value);
                this->_size = count;
                return;
            }
            return;
        }

        iterator insert(iterator position, const value_type &val)
        {
            int positionI = 0;
            for (iterator it = this->begin(); it != position; ++it)
                positionI++;
            if (this->capacity() == this->_size)
            {
                this->increaseCapacity();
                position = this->_data + positionI;
            }

            int tmp = this->_size ? *position : 0;
            this->_alloc.construct(position, val);
            this->_size++;

            for (iterator it = (position + 1); it != this->end(); ++it)
            {
                int tmpCurr = *it;
                this->_alloc.construct(it, tmp);
                tmp = tmpCurr;
            }
            return position;
        }

        iterator insert(iterator position, size_type n, const value_type &val)
        {
            if (n == 0)
                return position;

            int positionI = 0;
            for (iterator it = this->begin(); it != position; ++it)
                positionI++;

            if (this->capacity() == this->_size)
            {
                size_type newMinCapacity = this->_capacity + n;
                size_type newCapacity = (newMinCapacity > (this->_capacity * 2)) ? newMinCapacity : this->_capacity * 2;
                this->allocateBiggerDataCopy(newCapacity);
                this->_capacity = newCapacity;
                position = this->_data + positionI;
            }

            ft::vector<value_type> tmp(position, this->end());

            for (size_type i = 0; i < n; ++i)
            {
                this->_alloc.construct(position + i, val);
                this->_size++;
            }
            for (size_type i = 0; i < tmp.size(); ++i)
                this->_alloc.construct(this->_data + positionI + n + i, tmp[i]);

            return position;
        }

        iterator insert(iterator position, iterator first, iterator last)
        {
            if ((last - first) == 0)
                return position;

            int positionI = 0;
            for (iterator it = this->begin(); it != position; ++it)
                positionI++;

            if (this->capacity() == this->_size)
            {
                size_type newMinCapacity = this->_capacity + (last - first);
                size_type newCapacity = (newMinCapacity > (this->_capacity * 2)) ? newMinCapacity : this->_capacity * 2;
                this->allocateBiggerDataCopy(newCapacity);
                this->_capacity = newCapacity;
                position = this->_data + positionI;
            }
            ft::vector<value_type> tmp(position, this->end());

            for (iterator it = first; it != last; ++it)
            {
                this->_alloc.construct(this->_data + positionI, *it);
                positionI++;
                this->_size++;
            }
            for (size_type i = 0; i < tmp.size(); ++i)
            {
                this->_alloc.construct(this->_data + positionI, tmp[i]);
                positionI++;
            }

            return position;
        }

        void clear()
        {
            for (size_type i = 0; i < this->_size; ++i)
                this->_alloc.destroy(this->_data + i);
            this->_size = 0;
        }

        void swap(vector &other)
        {
            ft::swap(this->_size, other._size);
            ft::swap(this->_capacity, other._capacity);
            ft::swap(this->_maxSize, other._maxSize);
            ft::swap(this->_data, other._data);
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
            return this->_data;
        }

    private:
        allocator_type _alloc;
        value_type *_data;

        size_type _size;
        size_type _capacity;
        size_type _maxSize;

        void destroyAllocatedData()
        {
            if (this->size())
                this->_alloc.destroy(this->_data);
            if (this->capacity())
                this->_alloc.deallocate(this->_data, this->_capacity);
        }

        void allocateBiggerDataCopy(size_type newCapacity)
        {
            value_type *tmp = this->_alloc.allocate(newCapacity);
            for (size_type i = 0; i < this->_size; ++i)
                this->_alloc.construct((tmp + i), this->_data[i]);
            this->destroyAllocatedData();
            this->_data = tmp;
        }

        void increaseCapacity()
        {
            size_type newCapacity = this->_capacity ? this->_capacity * 2 : 1;
            this->allocateBiggerDataCopy(newCapacity);
            this->_capacity = newCapacity;
        }
    };

    /* ----------------------------------
     * Relational operators
     * ---------------------------------- */
    template <class T, class Alloc>
    bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        if (lhs.size() != rhs.size())
            return false;
        return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }

    template <class T, class Alloc>
    bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        if (lhs.size() != rhs.size())
            return true;
        typedef typename Alloc::size_type size_type;
        for (size_type i = 0; i < lhs.size(); ++i)
        {
            if (lhs[i] != rhs[i])
                return true;
        }
        return false;
    }

    /* ----------------------------------
     * Swap
     * ---------------------------------- */
    template <class T, class Alloc>
    void swap(ft::vector<T, Alloc> &lhs,
              ft::vector<T, Alloc> &rhs)
    {
        lhs.swap(rhs);
    }
}
