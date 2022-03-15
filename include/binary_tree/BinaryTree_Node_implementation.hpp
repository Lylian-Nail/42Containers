/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinaryTree_Node_implementation.hpp                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:25:13 by lperson-          #+#    #+#             */
/*   Updated: 2022/03/15 14:26:31 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREE_NODE_IMPLEMENTATION_HPP

# define BINARY_TREE_NODE_IMPLEMENTATION_HPP

namespace ft
{

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
        m_allocator.destroy(m_data);
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