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
        explicit reverse_iterator(iterator_type x)
        {
            this->_current = iterator_type(x);
        }
        template <class U>
        reverse_iterator(const reverse_iterator<U> &other)
        {
            this->_current = reverse_iterator<U>(other);
        }

    private:
        Iterator _current;
    };
}