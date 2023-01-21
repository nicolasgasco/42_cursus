#pragma once

#include "iterator_traits_map.hpp"
#include "bst.hpp"

namespace ft
{
    template <class T>
    class map_iterator
    {
    public:
        typedef T node_type;
        typedef typename node_type::value_type value_type;
        typedef typename ft::iterator_traits_map<node_type>::difference_type difference_type;
        typedef typename ft::iterator_traits_map<node_type>::pointer pointer;
        typedef typename ft::iterator_traits_map<node_type>::pointer const const_pointer;
        typedef typename ft::iterator_traits_map<node_type>::reference reference;
        typedef typename ft::iterator_traits_map<node_type>::reference const const_reference;
        typedef typename ft::iterator_traits_map<node_type>::iterator_category iterator_category;

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

        map_iterator(const map_iterator &it)
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

        // Operators
        map_iterator operator++()
        {
            this->p = this->p->right();
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
    };
}