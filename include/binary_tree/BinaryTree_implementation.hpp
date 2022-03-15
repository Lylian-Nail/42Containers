/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinaryTree_implementation.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:21:51 by lperson-          #+#    #+#             */
/*   Updated: 2022/03/15 13:50:26 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREE_IMPLEMENTATION_HPP

# define BINARY_TREE_IMPLEMENTATION_HPP

namespace ft
{
    /*
     * Constructors and destructor
    */

    template <class T, class Compare, class Alloc>
    BinaryTree<T, Compare, Alloc>::BinaryTree(
        value_compare const &compare,
        allocator_type const &allocator
    ):
        m_root(NULL),
        m_size(0),
        m_compare(compare),
        m_allocator(allocator),
        m_node_allocator(allocator)
    {
        m_superRoot = m_node_allocator.allocate(sizeof(node_type));
    }

    template <class T, class Compare, class Alloc>
    BinaryTree<T, Compare, Alloc>::~BinaryTree()
    {
        // TODO: use iterators to clean allocated resources
    }

    /*
     * Getters
    */

    template <class T, class Compare, class Alloc>
    typename BinaryTree<T, Compare, Alloc>::value_compare
    BinaryTree<T, Compare, Alloc>::value_comp() const
    {
        return m_compare;
    }

    template <class T, class Compare, class Alloc>
    typename BinaryTree<T, Compare, Alloc>::allocator_type
    BinaryTree<T, Compare, Alloc>::get_allocator() const
    {
        return m_allocator;
    }

    /*
     * Iterator
    */

   template <class T, class Compare, class Alloc>
   typename BinaryTree<T, Compare, Alloc>::iterator
   BinaryTree<T, Compare, Alloc>::begin()
    {
        node_pointer first = m_superRoot;
        while (first->leftChild)
            first = first->leftChild;
        return iterator(first);
    }

    template <class T, class Compare, class Alloc>
    typename BinaryTree<T, Compare, Alloc>::const_iterator
    BinaryTree<T, Compare, Alloc>::begin() const
    {
        node_pointer first = m_superRoot;
        while (first->leftChild)
            first = first->leftChild;
        return const_iterator(first);
    }

    template <class T, class Compare, class Alloc>
    typename BinaryTree<T, Compare, Alloc>::iterator
    BinaryTree<T, Compare, Alloc>::end()
    {
        return iterator(m_superRoot);
    }

    template <class T, class Compare, class Alloc>
    typename BinaryTree<T, Compare, Alloc>::const_iterator
    BinaryTree<T, Compare, Alloc>::end() const
    {
        return const_iterator(m_superRoot);
    }

    /*
     * Implemention of Node class
    */

    /*
     * Constructors and destructor
    */

    template <class T, class Compare, class Alloc>
    BinaryTree<T, Compare, Alloc>::Node::Node():
        m_data(),
        m_parent(NULL),
        m_leftChild(NULL),
        m_rightChild(NULL)
    {
    }

    template <class T, class Compare, class Alloc>
    BinaryTree<T, Compare, Alloc>::Node::Node(const_reference data):
        m_data(data),
        m_parent(NULL),
        m_leftChild(NULL),
        m_rightChild(NULL)
    {
    }

    template <class T, class Compare, class Alloc>
    BinaryTree<T, Compare, Alloc>::Node::Node(Node const &copy):
        m_data(copy.getData()),
        m_parent(copy.getParent()),
        m_leftChild(copy.getLeftChild()),
        m_rightChild(copy.getRightChild())
    {
    }

    template <class T, class Compare, class Alloc>
    BinaryTree<T, Compare, Alloc>::Node::~Node()
    {
    }

    /*
     * Getters
    */

    template <class T, class Compare, class Alloc>
    typename BinaryTree<T, Compare, Alloc>::const_reference
    BinaryTree<T, Compare, Alloc>::Node::getData() const
    {
        return m_data;
    }

    template <class T, class Compare, class Alloc>
    typename BinaryTree<T, Compare, Alloc>::pointer
    BinaryTree<T, Compare, Alloc>::Node::getParent() const
    {
        return m_parent;
    }

    template <class T, class Compare, class Alloc>
    typename BinaryTree<T, Compare, Alloc>::pointer
    BinaryTree<T, Compare, Alloc>::Node::getLeftChild() const
    {
        return m_leftChild;
    }

    template <class T, class Compare, class Alloc>
    typename BinaryTree<T, Compare, Alloc>::pointer
    BinaryTree<T, Compare, Alloc>::Node::getRightChild() const
    {
        return m_rightChild;
    }

    /*
     * Assignement
    */

    template <class T, class Compare, class Alloc>
    typename BinaryTree<T, Compare, Alloc>::Node &
    BinaryTree<T, Compare, Alloc>::Node::operator=(Node const &rhs)
    {
        if (this != &rhs)
        {
            m_data = rhs.getData();
            m_parent = rhs.getParent();
            m_leftChild = rhs.getLeftChild();
            m_rightChild = rhs.getRightChild();
        }
        return *this;
    }

    /*
     * In order iterator for binary tree 
    */

    template <class T, class Compare, class Alloc>
    template <class Node>
    BinaryTree<T, Compare, Alloc>::in_order_iterator<Node>::in_order_iterator():
        m_node(NULL)
    {
    }

    template <class T, class Compare, class Alloc>
    template <class Node>
    BinaryTree<T, Compare, Alloc>::in_order_iterator<Node>::in_order_iterator(
        Node const &node
    ):
        m_node(node)
    {
    }

    template <class T, class Compare, class Alloc>
    template <class Node>
    template <class Pointer>
    BinaryTree<T, Compare, Alloc>::in_order_iterator<Node>::in_order_iterator(
        in_order_iterator<Pointer> const &copy
    ):
        m_node(copy.base())
    {
    }

    template <class T, class Compare, class Alloc>
    template <class Node>
    BinaryTree<T, Compare, Alloc>::in_order_iterator<Node>::~in_order_iterator()
    {
    }

    template <class T, class Compare, class Alloc>
    template <class Node>
    typename BinaryTree<T, Compare, Alloc>
    ::in_order_iterator<Node>::in_order_iterator &
    BinaryTree<T, Compare, Alloc>::in_order_iterator<Node>::operator=(
        in_order_iterator const &rhs
    )
    {
        if (this != rhs)
        {
            m_node = rhs.base();
        }
    }

    template <class T, class Compare, class Alloc>
    template <class Node>
    Node BinaryTree<T, Compare, Alloc>::in_order_iterator<Node>::base() const
    {
        return m_node;
    }

    template <class T, class Compare, class Alloc>
    template <class Node>
    typename BinaryTree<T, Compare, Alloc>::in_order_iterator<Node>::reference
    BinaryTree<T, Compare, Alloc>::in_order_iterator<Node>::operator*() const
    {
        return m_node.data;
    }

    template <class T, class Compare, class Alloc>
    template <class Node>
    typename BinaryTree<T, Compare, Alloc>::in_order_iterator<Node>::pointer
    BinaryTree<T, Compare, Alloc>::in_order_iterator<Node>::operator->() const
    {
        return &m_node.data;
    }

    template <class T, class Compare, class Alloc>
    template <class Node>
    typename BinaryTree<T, Compare, Alloc>::in_order_iterator<Node> &
    BinaryTree<T, Compare, Alloc>::in_order_iterator<Node>::operator++()
    {
        increment();
        return *this;
    }

    template <class T, class Compare, class Alloc>
    template <class Node>
    typename BinaryTree<T, Compare, Alloc>::in_order_iterator<Node>
    BinaryTree<T, Compare, Alloc>::in_order_iterator<Node>::operator++(int)
    {
        in_order_iterator copy(*this);
        ++(*this);
        return copy;
    }

    template <class T, class Compare, class Alloc>
    template <class Node>
    void BinaryTree<T, Compare, Alloc>::in_order_iterator<Node>::increment()
    {
        // If parent and has right child
        if (m_node->m_rightChild)
        {
            // We reach end of left branch of right child
            m_node = m_node->rightChild;
            while (m_node->leftChild)
                m_node = m_node.leftChild;
        }
        else
        {
            // If we are right child of parent we ascend the branch
            Node parent = m_node->parent;
            while (parent->rightChild == m_node)
            {
                m_node = parent;
                parent = m_node->parent;
            }
            if (m_node->rightChild != parent)
                m_node = parent;
        }
    }

    template <class T, class Compare, class Alloc>
    template <class Node>
    typename BinaryTree<T, Compare, Alloc>::in_order_iterator<Node> &
    BinaryTree<T, Compare, Alloc>::in_order_iterator<Node>::operator--()
    {
        decrement();
        return *this;
    }

    template <class T, class Compare, class Alloc>
    template <class Node>
    typename BinaryTree<T, Compare, Alloc>::in_order_iterator<Node>
    BinaryTree<T, Compare, Alloc>::in_order_iterator<Node>::operator--(int)
    {
        in_order_iterator copy(*this);
        --(*this);
        return copy;
    }

    template <class T, class Compare, class Alloc>
    template <class Node>
    void BinaryTree<T, Compare, Alloc>::in_order_iterator<Node>::decrement()
    {
        // If parent has a left child
        if (m_node->m_leftChild)
        {
            // we reach end of right branch of left child
            m_node = m_node->leftChild;
            while (m_node->rightChild)
                m_node = m_node->rightChild;
        }
        else
        {
            // If we are left child of parent we ascend the branch
            Node parent = m_node->parent;
            while (parent == m_node->leftChild)
            {
                m_node = parent;
                parent = m_node->parent;
            }
            if (m_node->leftChild != parent)
                m_node = parent;
        }
    }

    template <class T, class Compare, class Alloc, class Node>
    bool operator==(
        typename BinaryTree<T, Compare, Alloc>::in_order_iterator<Node> it0,
        typename BinaryTree<T, Compare, Alloc>::in_order_iterator<Node> it1
    )
    {
        return it0.base() == it1.base();
    }

    template <class T, class Compare, class Alloc, class Node0, class Node1>
    bool operator==(
        typename BinaryTree<T, Compare, Alloc>::in_order_iterator<Node0> it0,
        typename BinaryTree<T, Compare, Alloc>::in_order_iterator<Node1> it1
    )
    {
        return it0.base() == it1.base();
    }

    template <class T, class Compare, class Alloc, class Node>
    bool operator!=(
        typename BinaryTree<T, Compare, Alloc>::in_order_iterator<Node> it0,
        typename BinaryTree<T, Compare, Alloc>::in_order_iterator<Node> it1
    )
    {
        return !(it0 == it1);
    }

    template <class T, class Compare, class Alloc, class Node0, class Node1>
    bool operator!=(
        typename BinaryTree<T, Compare, Alloc>::in_order_iterator<Node0> it0,
        typename BinaryTree<T, Compare, Alloc>::in_order_iterator<Node1> it1
    )
    {
        return !(it0 == it1);
    }

}

#endif
