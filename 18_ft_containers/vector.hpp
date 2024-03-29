#pragma once

#include "algorithms.hpp"
#include "enable_if.hpp"
#include "iterator_traits.hpp"
#include "iterator.hpp"
#include "reverse_iterator.hpp"
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
        typedef typename allocator_type::size_type size_type;
        typedef typename allocator_type::difference_type difference_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef typename ft::iterator<value_type> iterator;
        typedef typename ft::iterator<value_type const> const_iterator;
        // typedef typename ft::iterator_traits<typename ft::iterator<value_type> >::pointer iterator;
        // typedef typename ft::iterator_traits<typename ft::iterator<value_type const> >::pointer const_iterator;
        typedef typename ft::reverse_iterator<iterator> reverse_iterator;
        typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;

    protected:
        allocator_type _alloc;
        value_type *_data;

        size_type _size;
        size_type _capacity;

    public:
        /* ----------------------------------
         * LIFECYCLE
         * ---------------------------------- */
        // Empty constructor
        vector(const allocator_type &alloc = allocator_type()) : _size(0), _capacity(0)
        {
            this->_alloc = alloc;
            this->_data = this->_alloc.allocate(0);
        }

        // Fill constructors
        vector(size_type count, const value_type &value = value_type(), const allocator_type &alloc = allocator_type()) : _size(count), _capacity(count)
        {
            this->_alloc = alloc;
            this->_data = this->_alloc.allocate(count);
            for (size_type i = 0; i < count; ++i)
                this->_alloc.construct((this->_data + i), value_type(value));
        }

        // Range constructor
        template <class InputIterator>
        vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
               typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = true)
        {
            size_type rangeDistance = 0;
            for (InputIterator it = first; it != last; ++it)
                rangeDistance++;

            this->_alloc = alloc;
            this->_data = this->_alloc.allocate(rangeDistance);

            for (size_type i = 0; i < rangeDistance; ++i, ++first)
                this->_alloc.construct((this->_data + i), *first);
            this->_size = rangeDistance;

            this->_capacity = rangeDistance;
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
            if (*this == other)
                return (*this);

            if (this->size())
                this->_alloc.destroy(this->_data);

            if (this->_capacity < other.size())
                this->reserve(other.size());

            for (size_type i = 0; i < other.size(); ++i)
                this->_alloc.construct((this->_data + i), other[i]);
            this->_size = other.size();
            return *this;
        }

        // Destructor
        ~vector()
        {
            if (this->size())
                this->_alloc.destroy(this->_data);
            if (this->capacity())
                this->_alloc.deallocate(this->_data, this->_capacity);
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
            return const_iterator(this->_data);
        }

        iterator end()
        {
            return iterator(this->_data + this->_size);
        }
        const_iterator end() const
        {
            return const_iterator(this->_data + this->_size);
        }

        reverse_iterator rbegin()
        {
            return reverse_iterator(this->end());
        }
        const_reverse_iterator rbegin() const
        {
            return const_reverse_iterator(this->end());
        }

        reverse_iterator rend()
        {
            return reverse_iterator(this->begin());
        }
        const_reverse_iterator rend() const
        {
            return const_reverse_iterator(this->begin());
        }

        /* ----------------------------------
         * Member functions
         * ---------------------------------- */

        /*
         * Allocator
         */
        allocator_type get_allocator() const
        {
            return this->_alloc;
        }

        /*
         * Capacity
         */
        bool empty() const
        {
            return this->_size == 0;
        }

        size_type size() const
        {
            return this->_size;
        }

        size_type max_size() const
        {
            return this->_alloc.max_size();
        }

        size_type capacity() const
        {
            return this->_capacity;
        }

        void reserve(size_type new_cap)
        {
            if (new_cap > this->max_size() || new_cap < 0)
                throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
            if (new_cap <= this->_capacity)
                return;

            value_type *tmp = this->_alloc.allocate(new_cap);
            for (size_type i = 0; i < this->_size; ++i)
                this->_alloc.construct((tmp + i), this->_data[i]);

            if (this->size())
                this->_alloc.destroy(this->_data);
            if (this->capacity())
                this->_alloc.deallocate(this->_data, this->_capacity);

            this->_data = tmp;
            this->_capacity = new_cap;
        }

        /*
         * Modifiers
         */
        void assign(size_type n, const value_type &val)
        {
            if (n <= 0)
                return;

            if (this->size())
                this->_alloc.destroy(this->_data);

            if (n > this->_capacity)
                this->reserve(n);

            for (size_type i = 0; i < n; ++i)
                this->_alloc.construct(this->_data + i, value_type(val));
            this->_size = n;
        }
        template <class InputIterator>
        void assign(InputIterator first, InputIterator last,
                    typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = true)
        {
            if (this->size())
                this->_alloc.destroy(this->_data);

            size_type newSize = 0;
            for (InputIterator it = first; it != last; ++it)
                newSize++;

            if (newSize == 0)
                return;

            if (newSize > this->_capacity)
                this->reserve(newSize);

            size_type i = 0;
            for (InputIterator it = first; it != last; ++it, ++i)
                this->_alloc.construct(this->_data + i, *it);

            this->_size = newSize;
        }

        void push_back(const value_type &value)
        {
            size_type newSize = this->_size + 1;
            if (newSize > this->max_size())
                return;

            if (newSize > this->_capacity)
            {
                size_type newCapacity = this->_capacity ? this->_capacity * 2 : 1;
                value_type *tmp = this->_alloc.allocate(newCapacity);
                if (this->_size)
                {
                    for (size_type i = 0; i < this->_size; ++i)
                        this->_alloc.construct((tmp + i), this->_data[i]);
                    this->_alloc.destroy(this->_data);
                    this->_alloc.deallocate(this->_data, this->_capacity);
                }
                this->_data = tmp;
                this->_capacity = newCapacity;
            }
            this->_alloc.construct((this->_data + this->_size), value);
            this->_size++;
        }

        void pop_back()
        {
            this->_alloc.destroy(this->_data + (this->_size - 1));
            this->_size--;
        }

        void resize(size_type count, value_type value = value_type())
        {
            if (count < 0 || count > this->max_size())
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
                    this->reserve(newCapacity);
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
            size_type positionI = 0;
            for (iterator it = this->begin(); it != position; ++it)
                positionI++;
            if (this->capacity() == this->_size)
            {
                size_type newCapacity = this->_capacity ? this->_capacity * 2 : 1;
                this->reserve(newCapacity);
                position = this->begin() + positionI;
            }

            value_type tmp = this->_size ? *position : 0;
            this->_alloc.construct(&(*position), val);
            this->_size++;

            for (iterator it = (position + 1); it != this->end(); ++it)
            {
                value_type tmpCurr = *it;
                this->_alloc.construct(&(*it), tmp);
                tmp = tmpCurr;
            }
            return position;
        }
        iterator insert(iterator position, size_type n, const value_type &val)
        {
            if (n == 0)
                return position;

            size_type positionI = 0;
            for (iterator it = this->begin(); it != position; ++it)
                positionI++;

            size_type newMinCapacity = this->_size + n;
            if (this->capacity() < newMinCapacity)
            {
                size_type newCapacity = (newMinCapacity > (this->_capacity * 2)) ? newMinCapacity : this->_capacity * 2;
                this->reserve(newCapacity);
                position = this->begin() + positionI;
            }

            ft::vector<value_type> tmp(position, this->end());

            for (size_type i = 0; i < n; ++i)
            {
                this->_alloc.construct(&(*(position + i)), val);
                this->_size++;
            }
            for (size_type i = 0; i < tmp.size(); ++i)
                this->_alloc.construct(this->_data + positionI + n + i, tmp[i]);

            return position;
        }
        template <class InputIterator>
        iterator insert(iterator position, InputIterator first, InputIterator last,
                        typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = true)
        {
            size_type iteratorsDistance = 0;
            for (InputIterator it = first; it != last; ++it)
                iteratorsDistance++;

            if (iteratorsDistance == 0)
                return position;

            size_type positionIndex = 0;
            for (iterator it = this->begin(); it != position; ++it)
                positionIndex++;

            size_type newMinCapacity = this->_size + iteratorsDistance;
            if (this->capacity() < newMinCapacity)
            {
                size_type newCapacity = (newMinCapacity > (this->_capacity * 2)) ? newMinCapacity : this->_capacity * 2;
                this->reserve(newCapacity);
                position = this->begin() + positionIndex;
            }

            ft::vector<value_type> tmp(position, this->end());

            for (InputIterator it = first; it != last; ++it)
            {
                this->_alloc.construct(this->_data + positionIndex, *it);
                positionIndex++;
                this->_size++;
            }
            for (size_type i = 0; i < tmp.size(); ++i)
            {
                this->_alloc.construct(this->_data + positionIndex, tmp[i]);
                positionIndex++;
            }

            return position;
        }

        iterator erase(iterator position)
        {
            this->_alloc.destroy(&(*position));
            for (iterator it = position; it < (this->end() - 1); ++it)
            {
                this->_alloc.destroy(&(*(it)));
                this->_alloc.construct(&(*(it)), *(it + 1));
            }
            this->_alloc.destroy(this->_data + this->_size - 1);
            this->_size--;
            return position;
        }
        iterator erase(iterator first, iterator last)
        {
            if (last - first == 0)
                return last;
            ft::vector<value_type> tmp(last, this->end());

            for (iterator it = first; it < this->end(); ++it)
                this->_alloc.destroy(&(*it));
            this->_size -= last - first;

            for (size_type i = 0; i < tmp.size(); ++i)
                this->_alloc.construct(&(*(first + i)), tmp[i]);

            return first;
        }

        void clear()
        {
            for (size_type i = 0; i < this->_size; ++i)
                this->_alloc.destroy(this->_data + i);
            this->_size = 0;
        }

        void swap(vector &other)
        {
            ft::swap(this->_alloc, other._alloc);
            ft::swap(this->_size, other._size);
            ft::swap(this->_capacity, other._capacity);
            ft::swap(this->_data, other._data);
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
        return !(ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }

    template <class T, class Alloc>
    bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }

    template <class T, class Alloc>
    bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        bool isLessThan = ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
        bool isEqual = (lhs.size() != rhs.size()) ? false : ft::equal(lhs.begin(), lhs.end(), rhs.begin());

        return (isLessThan || isEqual) ? true : false;
    }

    template <class T, class Alloc>
    bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        bool isLessThan = ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
        bool isEqual = (lhs.size() != rhs.size()) ? false : ft::equal(lhs.begin(), lhs.end(), rhs.begin());

        return (!isLessThan && !isEqual) ? true : false;
    }

    template <class T, class Alloc>
    bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
    {
        bool isLessThan = ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
        bool isEqual = (lhs.size() != rhs.size()) ? false : ft::equal(lhs.begin(), lhs.end(), rhs.begin());

        return (!isLessThan || isEqual) ? true : false;
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
