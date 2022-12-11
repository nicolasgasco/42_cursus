#pragma once

#include "algorithms.hpp"
#include "enable_if.hpp"
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"
#include "pair.hpp"
#include <iostream>

namespace ft
{
    template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<typename ft::pair<const Key, T> > >
    class map
    {
    public:
        /*
         * MEMBER TYPES
         */
        typedef Key key_type;
        typedef T mapped_type;
        typedef typename ft::pair<const key_type, mapped_type> value_type;
        typedef Compare key_compare;
        // typedef   value_compare;
        typedef Allocator allocator_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef typename ft::iterator<typename ft::pair<Key, T> > iterator;
        typedef typename ft::iterator<typename ft::pair<const Key, T> > const_iterator;
        typedef typename ft::reverse_iterator<iterator> reverse_iterator;
        typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
        typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
        typedef typename allocator_type::size_type size_type;

    protected:
        allocator_type _alloc;
        key_compare _comp;

    public:
        /* ----------------------------------
         * LIFECYCLE
         * ---------------------------------- */
        // Empty
        explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : _alloc(alloc), _comp(comp)
        {
        }

        // Range
        template <class InputIterator>
        map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : _alloc(alloc), _comp(comp)
        {
        }

        // Copy
        map(const map &x) : _alloc(x._alloc), _comp(x._comp)
        {
        }

        map &operator=(const map &x);

        ~map()
        {
        }
    };
}
