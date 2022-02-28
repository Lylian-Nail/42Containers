/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinaryTree_implementation.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:21:51 by lperson-          #+#    #+#             */
/*   Updated: 2022/02/28 14:16:17 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREE_IMPLEMENTATION_HPP

# define BINARY_TREE_IMPLEMENTATION_HPP

namespace ft
{
    /*
     * Constructors and destructors
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

}

#endif
