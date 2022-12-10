#pragma once

#include "iterator_traits.hpp"

namespace ft
{

    template <class T>
    class iterator
    {
    public:
        typedef typename ft::iterator_traits<T *>::value_type value_type;
        typedef typename ft::iterator_traits<T *>::difference_type difference_type;
        typedef typename ft::iterator_traits<T *>::pointer pointer;
        typedef typename ft::iterator_traits<T *>::pointer const const_pointer;
        typedef typename ft::iterator_traits<T *>::reference reference;
        typedef typename ft::iterator_traits<T *>::reference const const_reference;
        typedef typename ft::iterator_traits<T *>::iterator_category iterator_category;

    protected:
        pointer p;

    public:
        /* ----------------------------------
         * LIFECYCLE
         * ---------------------------------- */
        iterator()
        {
            this->p = nullptr;
        }

        explicit iterator(pointer p) : p(p)
        {
        }

        iterator(const iterator<value_type> &it)
        {
            this->p = &(*it);
        }

        iterator &operator=(iterator const &other)
        {
            this->p = &(*other);
            return (*this);
        }

        virtual ~iterator() {}

        /* ----------------------------------
         * MEMBER FUNCTIONS
         * ---------------------------------- */
        // Access
        reference operator*()
        {
            return *(this->p);
        }
        const_reference operator*() const
        {
            return *(this->p);
        }

        pointer operator->()
        {
            return (this->p);
        }
        const_pointer operator->() const
        {
            return (this->p);
        }

        reference operator[](difference_type n)
        {
            return *(this->p + n);
        }
        const_reference operator[](difference_type n) const
        {
            return *(this->p + n);
        }

        // Operators
        iterator &operator++()
        {
            ++this->p;
            return *this;
        }
        iterator operator++(int)
        {
            iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        iterator &operator--()
        {
            --this->p;
            return *this;
        }
        iterator operator--(int)
        {
            iterator tmp = *this;
            --(*this);
            return tmp;
        }

        iterator operator+(difference_type n) const
        {
            return iterator(this->p + n);
        }
        iterator operator-(difference_type n) const
        {
            return iterator(this->p - n);
        }

        iterator &operator+=(difference_type n)
        {
            this->p += n;
            return *this;
        }
        iterator &operator-=(difference_type n)
        {
            this->p -= n;
            return *this;
        }

        // Distance operators
        difference_type operator-(iterator const &other) const
        {
            return (this->p - other.p);
        }

        // Reletional operator
        bool operator==(iterator const &other) const
        {
            return (this->p == other.p);
        }
        bool operator!=(iterator const &other) const
        {
            return (this->p != other.p);
        }
        bool operator<(iterator const &other) const
        {
            return (this->p < other.p);
        }
        bool operator<=(iterator const &other) const
        {
            return (this->p <= other.p);
        }
        bool operator>(iterator const &other) const
        {
            return (this->p > other.p);
        }
        bool operator>=(iterator const &other) const
        {
            return (this->p >= other.p);
        }
    };
}