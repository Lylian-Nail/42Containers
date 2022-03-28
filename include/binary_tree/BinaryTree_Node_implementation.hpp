/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinaryTree_Node_implementation.hpp                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:25:13 by lperson-          #+#    #+#             */
/*   Updated: 2022/03/28 12:26:01 by lperson-         ###   ########.fr       */
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
        data(),
        parent(NULL),
        leftChild(NULL),
        rightChild(NULL)
    {
    }

    template <class T, class Compare, class Alloc>
    BinaryTree<T, Compare, Alloc>::Node::Node(
        const_reference data, node_pointer parent
    ):
        data(data),
        parent(parent),
        leftChild(NULL),
        rightChild(NULL)
    {
    }

    template <class T, class Compare, class Alloc>
    BinaryTree<T, Compare, Alloc>::Node::Node(Node const &copy):
        data(copy.getData()),
        parent(copy.getParent()),
        leftChild(copy.getLeftChild()),
        rightChild(copy.getRightChild())
    {
    }

    template <class T, class Compare, class Alloc>
    BinaryTree<T, Compare, Alloc>::Node::~Node()
    {
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
            data = rhs.getData();
            parent = rhs.getParent();
            leftChild = rhs.getLeftChild();
            rightChild = rhs.getRightChild();
        }
        return *this;
    }
}

#endif