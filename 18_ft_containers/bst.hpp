#pragma once

#include "pair.hpp"

#include <iostream>

namespace ft
{
    template <class T1, class T2, class P = ft::pair<T1, T2> >
    class bst_node
    {

    public:
        /*
         * MEMBER TYPES
         */
        typedef bst_node<T1, T2> node_type;
        typedef T1 first_type;
        typedef T2 second_type;
        typedef P value_type;
        typedef std::size_t size_type;

        bst_node() : _data(value_type()), _left(nullptr), _right(nullptr)
        {
        }

        bst_node(value_type value)
        {
            this->_data = value;
            this->_left = this->_right = nullptr;
        }

        node_type *insert(node_type *root, value_type value)
        {
            if (root == nullptr)
                return new node_type(value);

            if (value > root->_data)
                root->_right = insert(root->_right, value);
            else if (value < root->_data)
                root->_left = insert(root->_left, value);

            return root;
        }

    public:
        value_type _data;
        bst_node *_left, *_right;
    };

    template <class T1, class T2, class P = ft::pair<T1, T2> >
    class bst
    {
    public:
        /*
         * MEMBER TYPES
         */
        typedef bst_node<T1, T2> node_type;
        typedef T1 first_type;
        typedef T2 second_type;
        typedef P value_type;
        typedef std::size_t size_type;

        bst()
        {
            this->root = new node_type();
        }

        bst(value_type value)
        {
            this->root = new node_type(value);
        }

        // Search for pair
        node_type *search(node_type *root, value_type value)
        {
            if (root == nullptr || root->_data == value)
                return root;

            if (root->_data < value)
                return search(root->_right, value);

            return search(root->_left, value);
        }
        node_type *search(value_type value)
        {
            return search(this->root, value);
        }

        // Search for first value
        node_type *search(node_type *root, first_type first)
        {
            if (root == nullptr || root->_data.first == first)
                return root;

            if (root->_data.first < first)
                return search(root->_right, first);

            return search(root->_left, first);
        }
        node_type *search(first_type first)
        {
            return search(this->root, first);
        }

        node_type *insert(value_type value)
        {
            return root->insert(this->root, value);
        }

        void inorder(node_type *root)
        {
            static size_type i = 0;
            if (root == nullptr)
                return;
            inorder(root->_left);
            std::cout << i <<  ") " << root->_data << std::endl;
            ++i;
            inorder(root->_right);
        }
        void inorder()
        {
            this->inorder(this->root);
        }

    private:
        node_type *root;
    };
}
