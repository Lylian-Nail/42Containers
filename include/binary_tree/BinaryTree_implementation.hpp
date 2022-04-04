/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinaryTree_implementation.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:21:51 by lperson-          #+#    #+#             */
/*   Updated: 2022/04/04 09:32:05 by lperson-         ###   ########.fr       */
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
        m_superRoot = create_node(value_type());
    }

    template <class T, class Compare, class Alloc>
    template <class InputIterator>
    BinaryTree<T, Compare, Alloc>::BinaryTree(
        typename enable_if<
            !is_integral<InputIterator>::value, InputIterator
        >::type first,
        InputIterator last,
        value_compare const &compare,
        allocator_type const &allocator
    ):
        m_root(NULL),
        m_size(0),
        m_compare(compare),
        m_allocator(allocator),
        m_node_allocator(allocator)
    {
        m_superRoot = create_node(value_type());
        insert(first, last);
    }

    template <class T, class Compare, class Alloc>
    BinaryTree<T, Compare, Alloc>::BinaryTree(BinaryTree const &copy):
        m_root(NULL),
        m_size(0),
        m_compare(copy.value_comp()),
        m_allocator(copy.get_allocator()),
        m_node_allocator(copy.get_allocator())
    {
        m_superRoot = create_node(value_type());
        insert(copy.begin(), copy.last());
    }

    template <class T, class Compare, class Alloc>
    BinaryTree<T, Compare, Alloc>::~BinaryTree()
    {
        if (!empty())
            this->clear();
        destroy_node(m_superRoot);
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
    pair<typename BinaryTree<T, Compare, Alloc>::iterator, bool>
    BinaryTree<T, Compare, Alloc>::insert(const_reference value)
    {
        if (m_root == NULL)
        {
            m_superRoot->rightChild = create_node(value, m_superRoot);
            m_root = m_superRoot->rightChild;
            m_size++;
            return make_pair(iterator(m_root), true);
        }
        return insert_node(m_root, value);
    }

    template <class T, class Compare, class Alloc>
    typename BinaryTree<T, Compare, Alloc>::iterator
    BinaryTree<T, Compare, Alloc>::insert(
        iterator position, const_reference value
    )
    {
        /*
         * If empty OR
         * precedent > position
         * OR
         * next < position
         *
         * position is not valid and insertion is done from root.
        */

        if (empty())
            return insert(value).first;
        iterator precedent = position;
        --precedent;
        if (begin() != position && m_compare(value, precedent->data))
            return insert_node(m_root, value).first;
        iterator next = position;
        ++next;
        if (end() != position && m_compare(next->data, value))
            return insert_node(m_root, value).first;
        return insert_node(position.base(), value).first;
    }

    template <class T, class Compare, class Alloc>
    template <class InputIterator>
    void BinaryTree<T, Compare, Alloc>::insert(
        typename enable_if<
            !is_integral<InputIterator>::value, InputIterator
        >::type first,
        InputIterator last
    )
    {
        for (; first != last; ++first)
            insert(*first);
    }

    template <class T, class Compare, class Alloc>
    void BinaryTree<T, Compare, Alloc>::clear()
    {
        clear_node(m_root);
    }

    /*
     * Iterator
    */

   template <class T, class Compare, class Alloc>
   typename BinaryTree<T, Compare, Alloc>::iterator
   BinaryTree<T, Compare, Alloc>::begin()
    {
        if (!m_root)
            return iterator(m_superRoot);

        node_pointer first = m_root;
        while (first->leftChild)
            first = first->leftChild;
        return iterator(first);
    }

    template <class T, class Compare, class Alloc>
    typename BinaryTree<T, Compare, Alloc>::const_iterator
    BinaryTree<T, Compare, Alloc>::begin() const
    {
        if (!m_root)
            return iterator(m_superRoot);

        node_pointer first = m_root;
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
    BinaryTree<T, Compare, Alloc>::create_node(
        const_reference value, node_pointer parent
    )
    {
        node_pointer node = m_node_allocator.allocate(sizeof(node_type));
        m_allocator.construct(&node->data, value);
        node->parent = parent;
        node->leftChild = NULL;
        node->rightChild = NULL;
        return node;
    }

    template <class T, class Compare, class Alloc>
    void BinaryTree<T, Compare, Alloc>::destroy_node(node_pointer node)
    {
        m_allocator.destroy(&node->data);
        m_node_allocator.deallocate(node, sizeof(node_type));
    }

    template <class T, class Compare, class Alloc>
    pair<typename BinaryTree<T, Compare, Alloc>::iterator, bool>
    BinaryTree<T, Compare, Alloc>::insert_node(
        node_pointer root, const_reference value
    )
    {
        node_pointer parent;
        bool compare;
        while (root != NULL)
        {
            parent = root;
            compare = m_compare(value, root->data);
            if (root->data == value)
                return make_pair(iterator(root), false);
            else if (compare)
                root = root->leftChild;
            else
                root = root->rightChild;
        }

        node_pointer newNode = create_node(value, parent);
        m_size++;
        if (compare)
            parent->leftChild = newNode;
        else
            parent->rightChild = newNode;
        return make_pair(iterator(newNode), true);
    }

    template <class T, class Compare, class Alloc>
    void BinaryTree<T, Compare, Alloc>::clear_node(node_pointer root)
    {
        if (root == NULL)
            return ;

        clear_node(root->leftChild);
        clear_node(root->rightChild);
        destroy_node(root);
    }
}

#endif
