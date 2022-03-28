/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinaryTree_implementation.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:21:51 by lperson-          #+#    #+#             */
/*   Updated: 2022/03/28 10:49:35 by lperson-         ###   ########.fr       */
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
        m_superRoot = create_node(T());
    }

    template <class T, class Compare, class Alloc>
    BinaryTree<T, Compare, Alloc>::~BinaryTree()
    {
        this->clear();
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

    template <class T, class Compare, class Alloc>
    bool BinaryTree<T, Compare, Alloc>::empty() const
    {
        return m_size == 0;
    }

    template <class T, class Compare, class Alloc>
    typename BinaryTree<T, Compare, Alloc>::size_type
    BinaryTree<T, Compare, Alloc>::size() const
    {
        return m_size;
    }

    template <class T, class Compare, class Alloc>
    typename BinaryTree<T, Compare, Alloc>::size_type
    BinaryTree<T, Compare, Alloc>::max_size() const
    {
        return m_allocator.max_size();
    }

    /*
     * Setters
    */

    template <class T, class Compare, class Alloc>
    void BinaryTree<T, Compare, Alloc>::clear()
    {
        iterator first = begin();
        const_iterator last = end();
        for (; first != last; first++)
        {
            m_node_allocator.deallocate(first.base(), sizeof(node_type));
        }
        m_node_allocator.deallocate(m_superRoot, sizeof(node_type));
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
        while (first->m_leftChild)
            first = first->m_leftChild;
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
     * Node utilities
    */

    template <class T, class Compare, class Alloc>
    typename BinaryTree<T, Compare, Alloc>::node_pointer
    BinaryTree<T, Compare, Alloc>::create_node(const_reference value)
    {
        node_pointer node = m_node_allocator.allocate(sizeof(node_type));
        m_allocator.construct(&node->data, value);
        node->parent = NULL;
        node->leftChild = NULL;
        node->rightChild = NULL;
        return node;
    }

    template <class T, class Compare, class Alloc>
    void BinaryTree<T, Compare, Alloc>::destroy_node(node_pointer node)
    {
        m_allocator.destroy(&node->data);
        m_node_allocator.deallocate(node);
    }
}

#endif
