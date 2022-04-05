/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinaryTree_implementation.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:21:51 by lperson-          #+#    #+#             */
/*   Updated: 2022/04/05 11:04:28 by lperson-         ###   ########.fr       */
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
    BinarySearchTree<T, Compare, Alloc>::BinarySearchTree(
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
    BinarySearchTree<T, Compare, Alloc>::BinarySearchTree(
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
    BinarySearchTree<T, Compare, Alloc>::BinarySearchTree(BinarySearchTree const &copy):
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
    BinarySearchTree<T, Compare, Alloc>::~BinarySearchTree()
    {
        if (!empty())
            this->clear();
        destroy_node(m_superRoot);
    }

    /*
     * Getters
    */

    template <class T, class Compare, class Alloc>
    typename BinarySearchTree<T, Compare, Alloc>::value_compare
    BinarySearchTree<T, Compare, Alloc>::value_comp() const
    {
        return m_compare;
    }

    template <class T, class Compare, class Alloc>
    typename BinarySearchTree<T, Compare, Alloc>::allocator_type
    BinarySearchTree<T, Compare, Alloc>::get_allocator() const
    {
        return m_allocator;
    }

    template <class T, class Compare, class Alloc>
    bool BinarySearchTree<T, Compare, Alloc>::empty() const
    {
        return m_size == 0;
    }

    template <class T, class Compare, class Alloc>
    typename BinarySearchTree<T, Compare, Alloc>::size_type
    BinarySearchTree<T, Compare, Alloc>::size() const
    {
        return m_size;
    }

    template <class T, class Compare, class Alloc>
    typename BinarySearchTree<T, Compare, Alloc>::size_type
    BinarySearchTree<T, Compare, Alloc>::max_size() const
    {
        return m_allocator.max_size();
    }

    template <class T, class Compare, class Alloc>
    typename BinarySearchTree<T, Compare, Alloc>::size_type
    BinarySearchTree<T, Compare, Alloc>::count(const_reference value) const
    {
        if (find(value) != end())
            return 1;
        return 0;
    }

    template <class T, class Compare, class Alloc>
    typename BinarySearchTree<T, Compare, Alloc>::iterator
    BinarySearchTree<T, Compare, Alloc>::find(const_reference value) const
    {
        node_pointer current = m_root;
        while (current != NULL)
        {
            if (m_compare(value, current->data))
                current = current->leftChild;
            else if (m_compare(current->data, value))
                current = current->rightChild;
            else
                return iterator(current);
        }
        return iterator(m_superRoot);
    }

    template <class T, class Compare, class Alloc>
    typename BinarySearchTree<T, Compare, Alloc>::iterator
    BinarySearchTree<T, Compare, Alloc>::lower_bound(const_reference value) const
    {
        node_pointer current = m_root;
        node_pointer lower_bound = m_superRoot;
        while (current != NULL)
        {
            if (!m_compare(current->data, value))
            {
                lower_bound = current;
                current = current->leftChild;
            }
            else
                current = current->rightChild;
        }
        return iterator(lower_bound);
    }

    template <class T, class Compare, class Alloc>
    typename BinarySearchTree<T, Compare, Alloc>::iterator
    BinarySearchTree<T, Compare, Alloc>::upper_bound(const_reference value) const
    {
        node_pointer current = m_root;
        node_pointer upper_bound = m_superRoot;
        while (current != NULL)
        {
            if (m_compare(value, current->data))
            {
                upper_bound = current;
                current = current->leftChild;
            }
            else
                current = current->rightChild;
        }
        return iterator(upper_bound);
    }

    template <class T, class Compare, class Alloc>
    pair<
        typename BinarySearchTree<T, Compare, Alloc>::iterator,
        typename BinarySearchTree<T, Compare, Alloc>::iterator
    >
    BinarySearchTree<T, Compare, Alloc>::equal_range(const_reference value) const
    {
        iterator lower_bound = this->lower_bound(value);
        return make_pair(lower_bound, lower_bound);
    }

    /*
     * Setters
    */

    template <class T, class Compare, class Alloc>
    pair<typename BinarySearchTree<T, Compare, Alloc>::iterator, bool>
    BinarySearchTree<T, Compare, Alloc>::insert(const_reference value)
    {
        if (m_root == NULL)
        {
            m_superRoot->rightChild = create_node(value, m_superRoot);
            m_superRoot->leftChild = m_superRoot->rightChild;
            m_root = m_superRoot->rightChild;
            m_size++;
            return make_pair(iterator(m_root), true);
        }
        return insert_node(m_root, value);
    }

    template <class T, class Compare, class Alloc>
    typename BinarySearchTree<T, Compare, Alloc>::iterator
    BinarySearchTree<T, Compare, Alloc>::insert(
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
        if (begin() != position && m_compare(value, *precedent))
            return insert_node(m_root, value).first;
        iterator next = position;
        ++next;
        if (end() != position && m_compare(*next, value))
            return insert_node(m_root, value).first;
        return insert_node(position.base(), value).first;
    }

    template <class T, class Compare, class Alloc>
    template <class InputIterator>
    void BinarySearchTree<T, Compare, Alloc>::insert(
        typename enable_if<
            !is_integral<InputIterator>::value, InputIterator
        >::type first,
        InputIterator last
    )
    {
        for (; first != last; ++first)
        {
            insert(*first);
        }
    }

    template <class T, class Compare, class Alloc>
    void BinarySearchTree<T, Compare, Alloc>::clear()
    {
        clear_node(m_root);
        m_root = NULL;
    }

    /*
     * Iterator
    */

   template <class T, class Compare, class Alloc>
   typename BinarySearchTree<T, Compare, Alloc>::iterator
   BinarySearchTree<T, Compare, Alloc>::begin()
    {
        if (!m_root)
            return iterator(m_superRoot);

        node_pointer first = m_root;
        while (first->leftChild)
            first = first->leftChild;
        return iterator(first);
    }

    template <class T, class Compare, class Alloc>
    typename BinarySearchTree<T, Compare, Alloc>::const_iterator
    BinarySearchTree<T, Compare, Alloc>::begin() const
    {
        if (!m_root)
            return iterator(m_superRoot);

        node_pointer first = m_root;
        while (first->leftChild)
            first = first->leftChild;
        return const_iterator(first);
    }

    template <class T, class Compare, class Alloc>
    typename BinarySearchTree<T, Compare, Alloc>::iterator
    BinarySearchTree<T, Compare, Alloc>::end()
    {
        return iterator(m_superRoot);
    }

    template <class T, class Compare, class Alloc>
    typename BinarySearchTree<T, Compare, Alloc>::const_iterator
    BinarySearchTree<T, Compare, Alloc>::end() const
    {
        return const_iterator(m_superRoot);
    }

    template <class T, class Compare, class Alloc>
    typename BinarySearchTree<T, Compare, Alloc>::reverse_iterator
    BinarySearchTree<T, Compare, Alloc>::rbegin()
    {
        return reverse_iterator(end());
    }

    template <class T, class Compare, class Alloc>
    typename BinarySearchTree<T, Compare, Alloc>::const_reverse_iterator
    BinarySearchTree<T, Compare, Alloc>::rbegin() const
    {
        return reverse_iterator(end());
    }

    template <class T, class Compare, class Alloc>
    typename BinarySearchTree<T, Compare, Alloc>::reverse_iterator
    BinarySearchTree<T, Compare, Alloc>::rend()
    {
        return reverse_iterator(begin());
    }

    template <class T, class Compare, class Alloc>
    typename BinarySearchTree<T, Compare, Alloc>::const_reverse_iterator
    BinarySearchTree<T, Compare, Alloc>::rend() const
    {
        return reverse_iterator(begin());
    }

    /*
     * Operator overload
    */

    template <class T, class Compare, class Alloc>
    BinarySearchTree<T, Compare, Alloc> &
    BinarySearchTree<T, Compare, Alloc>::operator=(BinarySearchTree const &rhs)
    {
        if (this != &rhs)
        {
            // TODO: erase only already existing nodes
            m_compare = rhs.value_comp();
            if (!empty())
                clear();
            insert(rhs.begin(), rhs.end());
        }
        return *this;
    }

    /*
     * Node utilities
    */

    template <class T, class Compare, class Alloc>
    typename BinarySearchTree<T, Compare, Alloc>::node_pointer
    BinarySearchTree<T, Compare, Alloc>::create_node(
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
    void BinarySearchTree<T, Compare, Alloc>::destroy_node(node_pointer node)
    {
        m_allocator.destroy(&node->data);
        m_node_allocator.deallocate(node, sizeof(node_type));
    }

    template <class T, class Compare, class Alloc>
    pair<typename BinarySearchTree<T, Compare, Alloc>::iterator, bool>
    BinarySearchTree<T, Compare, Alloc>::insert_node(
        node_pointer root, const_reference value
    )
    {
        node_pointer parent;
        bool lesser;
        bool greater;
        while (root != NULL)
        {
            parent = root;
            lesser = m_compare(value, root->data);
            greater = m_compare(root->data, value);
            if (lesser)
                root = root->leftChild;
            else if (greater)
                root = root->rightChild;
            else
                return make_pair(iterator(root), false);
        }

        node_pointer newNode = create_node(value, parent);
        m_size++;
        if (lesser)
            parent->leftChild = newNode;
        else
            parent->rightChild = newNode;
        return make_pair(iterator(newNode), true);
    }

    template <class T, class Compare, class Alloc>
    void BinarySearchTree<T, Compare, Alloc>::clear_node(node_pointer root)
    {
        if (root == NULL)
            return ;

        clear_node(root->leftChild);
        clear_node(root->rightChild);
        destroy_node(root);
        m_size--;
    }
}

#endif
