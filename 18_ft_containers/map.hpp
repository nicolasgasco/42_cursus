#pragma once

#include "algorithms.hpp"
#include "enable_if.hpp"
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"
#include "pair.hpp"
#include "bst.hpp"
#include <iostream>

namespace ft
{
    template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<typename ft::pair<const Key, T> > >
    class map
    {

    public:
        typedef Key key_type;
        typedef T mapped_type;
        typedef typename ft::pair<key_type, mapped_type> value_type;
        typedef Allocator allocator_type;
        typedef typename allocator_type::size_type size_type;
        typedef Compare key_compare;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef typename ft::bst<typename value_type::first_type, typename value_type::second_type, value_type> container_type;
        typedef typename ft::iterator<typename container_type::node_type::value_type> iterator;
        typedef typename ft::iterator<typename container_type::node_type::value_type const> const_iterator;
        typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
        typedef typename ft::reverse_iterator<iterator> reverse_iterator;
        typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;

    protected:
        /*
         * VALUE COMPARE SUBCLASS
         */
        class value_compare : public std::binary_function<value_type, value_type, bool>
        {
        public:
            typedef bool result_type;
            typedef value_type first_argument_type;
            typedef value_type second_argument_type;

            bool operator()(const value_type &lhs, const value_type &rhs) const
            {
                return comp(lhs.first, rhs.first);
            }

        protected:
            key_compare _comp;

            value_compare(key_compare c) : _comp(c)
            {
            }
        };

        allocator_type _alloc;
        key_compare _comp;
        container_type _data;
        size_type _size;

    public:
        /* ----------------------------------
         * LIFECYCLE
         * ---------------------------------- */
        // Empty
        explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : _alloc(alloc), _comp(comp), _data(container_type()), _size(0)
        {
            this->_data = container_type();
        }

        // Range
        template <class InputIterator>
        map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : _alloc(alloc), _comp(comp)
        {
            for (InputIterator it = first; it < last; ++it)
                this->_data.insert(*it);
        }

        // Copy
        map(const map &x) : _alloc(x._alloc), _comp(x._comp)
        {
        }

        map &operator=(const map &x);

        virtual ~map()
        {
        }

        /* ----------------------------------
         * Iterators
         * ---------------------------------- */
        iterator begin()
        {
            return iterator(this->_data.root());
        }
        const_iterator begin() const
        {
            return const_iterator(this->_data.root());
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
        size_type size() const
        {
            return this->_size;
        }

        size_type max_size() const
        {
            return this->_alloc.max_size() / 2;
        }

        bool empty() const
        {
            return this->_size == 0;
        }

        /*
         * Modifiers
         */
        pair<iterator, bool> insert(const value_type &val)
        {
            if (!this->_data.search(val))
            {
                iterator insertedValueIt = iterator(this->_data.insert(val));
                return pair<iterator, bool>(insertedValueIt, true);
            }
            return pair<iterator, bool>(iterator(), false);
        }
    };
}
