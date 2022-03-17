/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinaryTree_implementation.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:21:51 by lperson-          #+#    #+#             */
/*   Updated: 2022/03/17 10:06:27 by lperson-         ###   ########.fr       */
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
        iterator first = begin();
        iterator last = end();
        for (; first != last; first++)
        {
            m_node_allocator.deallocate(first.base(), sizeof(node_type));
        }
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
        while (first->m_leftChild)
            first = first->m_leftChild;
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

}

#endif
