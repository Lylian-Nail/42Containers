/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinaryTree_in_order_iterator_implementation        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:30:13 by lperson-          #+#    #+#             */
/*   Updated: 2022/04/04 12:40:24 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREE_IN_ORDER_IMPLEMENTATION_HPP

# define BINARY_TREE_IN_ORDER_IMPLEMENTATION_HPP

namespace ft
{
    /*
     * In order iterator for binary tree 
    */

    template <class T, class Compare, class Alloc>
    template <class Node, class Type>
    BinaryTree<
        T, Compare, Alloc
    >::in_order_iterator<Node, Type>::in_order_iterator():
        m_node(NULL)
    {
    }

    template <class T, class Compare, class Alloc>
    template <class Node, class Type>
    BinaryTree<
        T, Compare, Alloc
    >::in_order_iterator<Node, Type>::in_order_iterator(
        Node const &node
    ):
        m_node(node)
    {
    }

    template <class T, class Compare, class Alloc>
    template <class Node, class Type>
    template <class Node2, class Type2>
    BinaryTree<
        T, Compare, Alloc
    >::in_order_iterator<Node, Type>::in_order_iterator(
        in_order_iterator<Node2, Type2> const &copy
    ):
        m_node(copy.base())
    {
    }

    template <class T, class Compare, class Alloc>
    template <class Node, class Type>
    BinaryTree<
        T, Compare, Alloc
    >::in_order_iterator<Node, Type>::~in_order_iterator()
    {
    }

    template <class T, class Compare, class Alloc>
    template <class Node, class Type>
    typename BinaryTree<T, Compare, Alloc>::in_order_iterator<Node, Type> &
    BinaryTree<
        T, Compare, Alloc
    >::in_order_iterator<Node, Type>::operator=(
        in_order_iterator const &rhs
    )
    {
        if (this != &rhs)
        {
            m_node = rhs.base();
        }
        return *this;
    }

    template <class T, class Compare, class Alloc>
    template <class Node, class Type>
    Node BinaryTree<T, Compare, Alloc>::in_order_iterator<Node, Type>::base() const
    {
        return m_node;
    }

    template <class T, class Compare, class Alloc>
    template <class Node, class Type>
    typename BinaryTree<
        T, Compare, Alloc
    >::in_order_iterator<Node, Type>::reference
    BinaryTree<T, Compare, Alloc>::in_order_iterator<Node, Type>::operator*() const
    {
        return m_node->data;
    }

    template <class T, class Compare, class Alloc>
    template <class Node, class Type>
    typename BinaryTree<
        T, Compare, Alloc
    >::in_order_iterator<Node, Type>::pointer
    BinaryTree<T, Compare, Alloc>::in_order_iterator<Node, Type>::operator->() const
    {
        return &m_node->data;
    }

    template <class T, class Compare, class Alloc>
    template <class Node, class Type>
    typename BinaryTree<
        T, Compare, Alloc
    >::in_order_iterator<Node, Type> &
    BinaryTree<T, Compare, Alloc>::in_order_iterator<Node, Type>::operator++()
    {
        increment();
        return *this;
    }

    template <class T, class Compare, class Alloc>
    template <class Node, class Type>
    typename BinaryTree<
        T, Compare, Alloc
    >::in_order_iterator<Node, Type>
    BinaryTree<
        T, Compare, Alloc
    >::in_order_iterator<Node, Type>::operator++(int)
    {
        in_order_iterator copy(*this);
        ++(*this);
        return copy;
    }

    template <class T, class Compare, class Alloc>
    template <class Node, class Type>
    void BinaryTree<
        T, Compare, Alloc
    >::in_order_iterator<Node, Type>::increment()
    {
        // If parent and has right child
        if (m_node->rightChild)
        {
            // We reach end of left branch of right child
            m_node = m_node->rightChild;
            while (m_node->leftChild)
                m_node = m_node->leftChild;
        }
        else
        {
            // If we are right child of parent we ascend the branch
            Node parent = m_node->parent;
            while (parent && parent->rightChild == m_node)
            {
                m_node = parent;
                parent = m_node->parent;
            }
            if (parent != NULL && m_node->rightChild != parent)
                m_node = parent;
        }
    }

    template <class T, class Compare, class Alloc>
    template <class Node, class Type>
    typename BinaryTree<T, Compare, Alloc>::in_order_iterator<Node, Type> &
    BinaryTree<T, Compare, Alloc>::in_order_iterator<Node, Type>::operator--()
    {
        decrement();
        return *this;
    }

    template <class T, class Compare, class Alloc>
    template <class Node, class Type>
    typename BinaryTree<T, Compare, Alloc>::in_order_iterator<Node, Type>
    BinaryTree<
        T, Compare, Alloc
    >::in_order_iterator<Node, Type>::operator--(int)
    {
        in_order_iterator copy(*this);
        --(*this);
        return copy;
    }

    template <class T, class Compare, class Alloc>
    template <class Node, class Type>
    void BinaryTree<
        T, Compare, Alloc
    >::in_order_iterator<Node, Type>::decrement()
    {
        // If parent has a left child
        if (m_node->leftChild)
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
}

#endif
