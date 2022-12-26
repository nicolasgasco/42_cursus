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
        typedef P value_type;
        typedef typename value_type::first_type first_type;
        typedef typename value_type::second_type second_type;
        typedef std::size_t size_type;

        bst_node() : _data(value_type()), _left(nullptr), _right(nullptr)
        {
        }

        bst_node(value_type value)
        {
            this->_data = value;
            this->_left = this->_right = nullptr;
        }

        bst_node(const bst_node &other)
        {
            *this = other;
        }

        bst_node &operator=(const bst_node &other)
        {
            this->_data = value_type(other.data());
            this->_left = other.left();
            this->_right = other.right();
            return *this;
        }

        value_type data() const
        {
            return this->_data;
        }

        bst_node *left() const
        {
            return this->_left;
        }

        bst_node *right() const
        {
            return this->_right;
        }

        node_type *insert(node_type *root, value_type value)
        {
            if (root == nullptr)
                return new node_type(value);

            if (value > root->data())
                root->_right = insert(root->right(), value);
            else if (value < root->data())
                root->_left = insert(root->left(), value);
            return root;
        }

    private:
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
            this->_root = new node_type();
        }

        bst(value_type value)
        {
            this->_root = new node_type(value);
        }

        bst(const bst &other)
        {
            *this = other;
        }

        bst &operator=(const bst &other)
        {
            this->_root = new node_type(other.root()->data());
            return *this;
        }

        node_type *root() const
        {
            return this->_root;
        }

        // Search for pair
        node_type *search(node_type *root, value_type value)
        {
            if (root == nullptr || root->data() == value)
                return root;

            if (root->data() < value)
                return search(root->right(), value);

            return search(root->left(), value);
        }
        node_type *search(value_type value)
        {
            return search(this->_root, value);
        }

        // Search for first value
        node_type *search(node_type *root, first_type first)
        {
            if (root == nullptr || root->data().first == first)
                return root;

            if (root->data().first < first)
                return search(root->right(), first);

            return search(root->left(), first);
        }
        node_type *search(first_type first)
        {
            return search(this->_root, first);
        }

        node_type *insert(value_type value)
        {
            return this->_root->insert(this->_root, value);
        }

        void inorder(node_type *root)
        {
            if (root == nullptr)
                return;
            inorder(root->left());
            std::cout << root->data() << std::endl;
            inorder(root->right());
        }
        void inorder()
        {
            this->inorder(this->_root);
        }

    private:
        node_type *_root;
    };
}
