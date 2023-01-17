#pragma once

#include "iterator_traits.hpp"
#include "bst.hpp"

namespace ft
{

    template <class T>
    class map_iterator
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
        map_iterator()
        {
            this->p = nullptr;
        }

        template <class T1, class T2>
        map_iterator(typename ft::bst_node<T1, T2> *p)
        {
            this->p = p->raw_data();
        }

        explicit map_iterator(pointer p) : p(p)
        {
        }

        map_iterator(const map_iterator<value_type> &it)
        {
            this->p = &(*it);
        }

        map_iterator &operator=(map_iterator const &other)
        {
            this->p = &(*other);
            return (*this);
        }

        virtual ~map_iterator() {}

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
        map_iterator &operator++()
        {
            ++this->p;
            return *this;
        }
        map_iterator operator++(int)
        {
            map_iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        map_iterator &operator--()
        {
            --this->p;
            return *this;
        }
        map_iterator operator--(int)
        {
            map_iterator tmp = *this;
            --(*this);
            return tmp;
        }

        map_iterator operator+(difference_type n) const
        {
            return map_iterator(this->p + n);
        }
        map_iterator operator-(difference_type n) const
        {
            return map_iterator(this->p - n);
        }

        map_iterator &operator+=(difference_type n)
        {
            this->p += n;
            return *this;
        }
        map_iterator &operator-=(difference_type n)
        {
            this->p -= n;
            return *this;
        }

        // Distance operators
        difference_type operator-(map_iterator const &other) const
        {
            return (this->p - other.p);
        }
    };

    // template <class Iter>
    // Iter operator+(typename Iter::difference_type n, const Iter &it)
    // {
    //     return Iter(it + n);
    // }
    template <class T1, class T2>
    typename ft::map_iterator<T1>::difference_type operator+(const ft::map_iterator<T1> &lhs, const ft::map_iterator<T2> &rhs)
    {
        return (&(*lhs) + &(*rhs));
    }

    // template <class Iter>
    // Iter operator-(typename Iter::difference_type n, const Iter &it)
    // {
    //     return Iter(it - n);
    // }
    template <class T1, class T2>
    typename ft::map_iterator<T1>::difference_type operator-(const ft::map_iterator<T1> &lhs, const ft::map_iterator<T2> &rhs)
    {
        return (&(*lhs) - &(*rhs));
    }

    // Reletional operator
    template <class T1, class T2>
    bool operator==(const ft::map_iterator<T1> &lhs, const ft::map_iterator<T2> &rhs)
    {
        return &(*lhs) == &(*rhs);
    }
    template <class T1, class T2>
    bool operator!=(const ft::map_iterator<T1> &lhs, const ft::map_iterator<T2> &rhs)
    {
        return &(*lhs) != &(*rhs);
    }
    template <class T1, class T2>
    bool operator<(const ft::map_iterator<T1> &lhs, const ft::map_iterator<T2> &rhs)
    {
        return &(*lhs) < &(*rhs);
    }
    template <class T1, class T2>
    bool operator<=(const ft::map_iterator<T1> &lhs, const ft::map_iterator<T2> &rhs)
    {
        return &(*lhs) <= &(*rhs);
    }
    template <class T1, class T2>
    bool operator>(const ft::map_iterator<T1> &lhs, const ft::map_iterator<T2> &rhs)
    {
        return &(*lhs) > &(*rhs);
    }
    template <class T1, class T2>
    bool operator>=(const ft::map_iterator<T1> &lhs, const ft::map_iterator<T2> &rhs)
    {
        return &(*lhs) >= &(*rhs);
    }
}