#pragma once

#include "iterator_traits.hpp"
#include "bst.hpp"

namespace ft
{
    template <class T>
    class map_iterator
    {
    public:
        typedef T node_type;
        typedef typename node_type::value_type value_type;
        typedef typename ft::iterator_traits<node_type>::difference_type difference_type;
        typedef typename ft::iterator_traits<node_type>::pointer pointer;
        typedef typename ft::iterator_traits<node_type>::pointer const const_pointer;
        typedef typename ft::iterator_traits<node_type>::reference reference;
        typedef typename ft::iterator_traits<node_type>::reference const const_reference;
        typedef typename ft::iterator_traits<node_type>::iterator_category iterator_category;

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

        map_iterator(pointer p)
        {
            this->p = p;
        }

        // map_iterator(const map_iterator &it)
        // {
        //     this->p = &(*it);
        // }

        // map_iterator &operator=(map_iterator const &other)
        // {
        //     this->p = &(*other);
        //     return (*this);
        // }

        virtual ~map_iterator() {}

        /* ----------------------------------
         * MEMBER FUNCTIONS
         * ---------------------------------- */
        // Access
        reference operator*()
        {
            return *(this->p->raw_data());
        }
        const_reference operator*() const
        {
            return *(this->p->raw_data());
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
}