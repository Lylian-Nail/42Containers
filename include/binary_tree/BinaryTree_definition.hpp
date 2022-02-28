/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinaryTree_definition.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 09:53:41 by lperson-          #+#    #+#             */
/*   Updated: 2022/02/28 16:28:36 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREE_DEFINITION_HPP

# define BINARY_TREE_DEFINITION_HPP

# include <memory>
# include <functional>

namespace ft
{

    /*
     * The binary tree class
     * A simple and naive binary tree class
    */

    template <
        class T,
        class Compare = std::less<T>,
        class Alloc = std::allocator<T>
    >
    class BinaryTree
    {
    public:
        /*
        * Template aliases
        */

        typedef T                                           value_type;
        typedef Compare                                     value_compare;
        typedef Alloc                                       allocator_type;
        typedef typename allocator_type::reference          reference;
        typedef typename allocator_type::const_reference    const_reference;
        typedef typename allocator_type::pointer            pointer;
        typedef typename allocator_type::const_pointer      const_pointer;
        typedef size_t                                      size_type;

        /*
         * Constructors and destructors
        */

        explicit BinaryTree(
            value_compare const &compare = value_compare(),
            allocator_type const &allocator = allocator_type()
        );
        ~BinaryTree();

        /*
         * Getters
        */

        value_compare value_comp() const;
        allocator_type get_allocator() const;

        /*
        * Create Binary Tree Node class
        * that contains data and pointer to parent, left child and right child.
        *
        * A node can be inserted in a tree,
        * it can be also a root or a leaf.
        * 
        * Node have to be allocated with correct allocator.
        */

        class Node
        {
        public:
            /*
            * Constructors and destructors
            */

            Node();
            explicit Node(const_reference data);
            Node(Node const &copy);
            ~Node();

            /*
            * Getters
            */

            const_reference getData() const;
            pointer         getParent() const;
            pointer         getLeftChild() const;
            pointer         getRightChild() const;

            /*
            * Assignement
            */

            Node &operator=(Node const &rhs);

        private:
            value_type      m_data;
            pointer         m_parent;
            pointer         m_leftChild;
            pointer         m_rightChild;

        };

    private:
        Node            *m_root;
        size_type       m_size;
        value_compare   m_compare;
        allocator_type  m_allocator;

    };

}

#endif
