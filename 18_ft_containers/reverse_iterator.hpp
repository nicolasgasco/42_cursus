#pragma once

#include "iterator_traits.hpp"

namespace ft
{
    template <class Iterator>
    class reverse_iterator
    {
    public:
        typedef Iterator iterator_type;
        typedef typename ft::iterator_traits<iterator_type>::iterator_category iterator_category;
        typedef typename ft::iterator_traits<iterator_type>::value_type value_type;
        typedef typename ft::iterator_traits<iterator_type>::difference_type difference_type;
        typedef typename ft::iterator_traits<iterator_type>::pointer pointer;
        typedef typename ft::iterator_traits<iterator_type>::reference reference;

        /* ----------------------------------
         * LIFECYCLE
         * ---------------------------------- */
        reverse_iterator()
        {
            this->_current = Iterator();
        }

        explicit reverse_iterator(iterator_type x) : _current(x)
        {
        }

        template <class Iter>
        reverse_iterator(const reverse_iterator<Iter> &rev_it) : _current(rev_it.base())
        {
        }

        /* ----------------------------------
         * MEMBER FUNCTIONS
         * ---------------------------------- */

        // Access
        iterator_type base() const
        {
            return this->_current;
        }

        reference operator*() const
        {
            return *(this->_current - 1);
        }
        pointer operator->() const
        {
            return *(this->_current - 1);
        }

        // Operators
        reverse_iterator &
        operator++()
        {
            --this->_current;
            return *this;
        }
        reverse_iterator &operator--()
        {
            ++this->_current;
            return *this;
        }

        reverse_iterator operator++(int)
        {
            reverse_iterator tmp = *this;
            ++(*this);
            return tmp;
        }
        reverse_iterator operator--(int)
        {
            reverse_iterator tmp = *this;
            --(*this);
            return tmp;
        }

        reverse_iterator operator+(difference_type n) const
        {
            return reverse_iterator(this->base() - n);
        }
        reverse_iterator operator-(difference_type n) const
        {
            return reverse_iterator(this->base() + n);
        }

        reverse_iterator &operator+=(difference_type n)
        {
            this->_current -= n;
            return *this;
        }
        reverse_iterator &operator-=(difference_type n)
        {
            this->_current += n;
            return *this;
        }

    protected:
        Iterator _current;
    };

    // Distance operators
    template <class Iter>
    reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter> &it)
    {
        return reverse_iterator<Iter>((it.base() - n));
    }

    template <class Iterator1, class Iterator2>
    typename reverse_iterator<Iterator1>::difference_type operator-(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
    {
        return (rhs.base() - lhs.base());
    }

    // Relational operators
    template <class Iterator1, class Iterator2>
    bool operator==(const ft::reverse_iterator<Iterator1> &lhs, const ft::reverse_iterator<Iterator2> &rhs)
    {
        return (lhs.base() == rhs.base());
    }
    template <class Iterator1, class Iterator2>
    bool operator!=(const ft::reverse_iterator<Iterator1> &lhs, const ft::reverse_iterator<Iterator2> &rhs)
    {
        return (lhs.base() != rhs.base());
    }
    template <class Iterator1, class Iterator2>
    bool operator<(const ft::reverse_iterator<Iterator1> &lhs, const ft::reverse_iterator<Iterator2> &rhs)
    {
        return (lhs.base() > rhs.base());
    }
    template <class Iterator1, class Iterator2>
    bool operator<=(const ft::reverse_iterator<Iterator1> &lhs, const ft::reverse_iterator<Iterator2> &rhs)
    {
        return (lhs.base() >= rhs.base());
    }
    template <class Iterator1, class Iterator2>
    bool operator>(const ft::reverse_iterator<Iterator1> &lhs, const ft::reverse_iterator<Iterator2> &rhs)
    {
        return (lhs.base() < rhs.base());
    }
    template <class Iterator1, class Iterator2>
    bool operator>=(const ft::reverse_iterator<Iterator1> &lhs, const ft::reverse_iterator<Iterator2> &rhs)
    {
        return (lhs.base() <= rhs.base());
    }
}