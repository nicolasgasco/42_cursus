#pragma once

#include "iterator_tags.hpp"
namespace ft
{
    template <class Iter>
    struct iterator_traits
    {
        typedef typename Iter::value_type value_type;
        typedef typename Iter::difference_type difference_type;
        typedef typename Iter::pointer pointer;
        typedef typename Iter::reference reference;
        typedef typename Iter::iterator_category iterator_category;
    };

    template <class T>
    struct iterator_traits<T *>
    {
        typedef T value_type;
        typedef std::ptrdiff_t difference_type;
        typedef T *pointer;
        typedef T &reference;
        typedef ft::random_access_iterator_tag iterator_category;
    };

    template <class T>
    struct iterator_traits<const T *>
    {
        typedef T value_type;
        typedef std::ptrdiff_t difference_type;
        typedef const T *pointer;
        typedef const T &reference;
        typedef ft::random_access_iterator_tag iterator_category;
    };
}