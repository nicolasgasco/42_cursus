#pragma once

#include "pair.hpp"

#include <iostream>

namespace ft
{
    template <class T1, class T2, class P = ft::pair<T1, T2> >
    class bst
    {
    private:
        struct node
        {
            P *data;
            node *left;
            node *right;
        };

    public:
        /*
         * MEMBER TYPES
         */
        typedef bst<T1, T2> bst_type;
        typedef typename bst::node node_type;
        typedef node_type *node_ptr;
        typedef T1 first_type;
        typedef T2 second_type;
        typedef P value_type;

        /* ----------------------------------
         * LIFECYCLE
         * ---------------------------------- */
        bst()
        {
            std::cout << "BST default constructor" << std::endl;
            root = nullptr;
        }

        bst(first_type first, second_type second)
        {
            std::cout << "BST default constructor" << std::endl;
            this->root = new node();
            this->root->data = new value_type(first, second);
            this->root->left = nullptr;
            this->root->right = nullptr;
        }

        /* ----------------------------------
         * Member functions
         * ---------------------------------- */
        bool empty() const
        {
            return this->root == nullptr ? true : false;
        }

        first_type first() const
        {
            return this->root->data->first;
        }

        second_type second() const
        {
            return this->root->data->second;
        }

    private:
        node_ptr root;
    };
}
