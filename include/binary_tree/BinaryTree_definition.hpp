/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinaryTree_definition.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 09:53:41 by lperson-          #+#    #+#             */
/*   Updated: 2022/03/15 11:53:28 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREE_DEFINITION_HPP

# define BINARY_TREE_DEFINITION_HPP

# include <memory>
# include <functional>
# include "iterator.hpp"

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

        /*
         * Create an iterator for binary tree class
        */

        template <class Node>
        class in_order_iterator : public iterator<
            std::bidirectional_iterator_tag,
            typename iterator_traits<Node>::value_type,
            typename iterator_traits<Node>::difference_type,
            typename iterator_traits<Node>::pointer,
            typename iterator_traits<Node>::reference
        >
        {
        public:
            typedef typename std::bidirectional_iterator_tag
                                                    iterator_category;
            typedef typename iterator_traits<Node>::value_type
                                                    value_type;
            typedef typename iterator_traits<Node>::difference_type
                                                    difference_type;
            typedef typename iterator_traits<Node>::pointer
                                                    pointer;
            typedef typename iterator_traits<Node>::reference
                                                    reference;

            in_order_iterator();
            in_order_iterator(Node const &node);
            template <class Pointer>
            in_order_iterator(in_order_iterator<Pointer> const &copy);
            ~in_order_iterator();

            in_order_iterator &operator=(in_order_iterator const &rhs);

            /*
             * Getter
            */

            Node base() const;

            /*
             * Forward iterator spec
            */

            reference operator*() const;
            pointer operator->() const;

            in_order_iterator &operator++();
            in_order_iterator operator++(int);

            /*
             * Bidirectional iterator spec
            */

            in_order_iterator &operator--();
            in_order_iterator operator--(int);

        private:
            Node    m_node;

            void increment();
            void decrement();
        };

    private:
        Node            *m_root;
        size_type       m_size;
        value_compare   m_compare;
        allocator_type  m_allocator;

    };

    template <class T, class Compare, class Alloc, class Node>
    bool operator==(
        typename BinaryTree<T, Compare, Alloc>::in_order_iterator<Node> it0,
        typename BinaryTree<T, Compare, Alloc>::in_order_iterator<Node> it1
    );

    template <class T, class Compare, class Alloc, class Node0, class Node1>
    bool operator==(
        typename BinaryTree<T, Compare, Alloc>::in_order_iterator<Node0> it0,
        typename BinaryTree<T, Compare, Alloc>::in_order_iterator<Node1> it1
    );

    template <class T, class Compare, class Alloc, class Node>
    bool operator!=(
        typename BinaryTree<T, Compare, Alloc>::in_order_iterator<Node> it0,
        typename BinaryTree<T, Compare, Alloc>::in_order_iterator<Node> it1
    );

    template <class T, class Compare, class Alloc, class Node0, class Node1>
    bool operator!=(
        typename BinaryTree<T, Compare, Alloc>::in_order_iterator<Node0> it0,
        typename BinaryTree<T, Compare, Alloc>::in_order_iterator<Node1> it1
    );

}
#endif
