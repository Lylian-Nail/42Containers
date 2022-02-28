/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinaryTree_implementation.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:21:51 by lperson-          #+#    #+#             */
/*   Updated: 2022/02/28 11:55:47 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREE_IMPLEMENTATION_HPP

# define BINARY_TREE_IMPLEMENTATION_HPP

namespace ft
{
    /*
     * Constructors and destructors
    */

    template <class T>
    BinaryTreeNode<T>::BinaryTreeNode():
        m_data(),
        m_parent(NULL),
        m_leftChild(NULL),
        m_rightChild(NULL)
    {
    }

    template <class T>
    BinaryTreeNode<T>::BinaryTreeNode(const_reference data):
        m_data(data),
        m_parent(NULL),
        m_leftChild(NULL),
        m_rightChild(NULL)
    {
    }

    template <class T>
    BinaryTreeNode<T>::BinaryTreeNode(BinaryTreeNode const &copy):
        m_data(copy.getData()),
        m_parent(copy.getParent()),
        m_leftChild(copy.getLeftChild()),
        m_rightChild(copy.getRightChild())
    {
    }

    template <class T>
    BinaryTreeNode<T>::~BinaryTreeNode()
    {
    }

    /*
     * Getters
    */

    template <class T>
    typename BinaryTreeNode<T>::const_reference
    BinaryTreeNode<T>::getData()const
    {
        return m_data;
    }

    template <class T>
    typename BinaryTreeNode<T>::pointer
    BinaryTreeNode<T>::getParent() const
    {
        return m_parent;
    }

    template <class T>
    typename BinaryTreeNode<T>::pointer
    BinaryTreeNode<T>::getLeftChild() const
    {
        return m_leftChild;
    }

    template <class T>
    typename BinaryTreeNode<T>::pointer
    BinaryTreeNode<T>::getRightChild() const
    {
        return m_rightChild;
    }

    /*
     * Assignement
    */

    template <class T>
    BinaryTreeNode<T> &BinaryTreeNode<T>::operator=(BinaryTreeNode const &rhs)
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
