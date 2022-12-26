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

        bst_node() : data(value_type()), left(nullptr), right(nullptr)
        {
        }

        bst_node(value_type value)
        {
            this->data = value;
            this->left = this->right = nullptr;
        }

        node_type *insert(node_type *root, value_type value)
        {
            if (root == nullptr)
                return new node_type(value);

            if (value > root->data)
                root->right = insert(root->right, value);
            else if (value < root->data)
                root->left = insert(root->left, value);

            return root;
        }

    public:
        value_type data;
        bst_node *left, *right;
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
            if (root == NULL || root->data == value)
                return root;

            if (root->data < value)
                return search(root->right, value);

            return search(root->left, value);
        }
        node_type *search(value_type value)
        {
            return search(this->root, value);
        }

        // Search for first value
        node_type *search(node_type *root, first_type first)
        {
            if (root == NULL || root->data.first == first)
                return root;

            if (root->data.first < first)
                return search(root->right, first);

            return search(root->left, first);
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
            if (root == nullptr)
                return;
            inorder(root->left);
            std::cout << root->data << std::endl;
            inorder(root->right);
        }
        void inorder()
        {
            this->inorder(this->root);
        }

    private:
        node_type *root;
    };
}
