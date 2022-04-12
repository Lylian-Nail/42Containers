/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinarySearchTree_in_order_iterator_implemen        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:30:13 by lperson-          #+#    #+#             */
/*   Updated: 2022/04/12 16:06:57 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_SEARCH_TREE_IN_ORDER_IMPLEMENTATION_HPP

# define BINARY_SEARCH_TREE_IN_ORDER_IMPLEMENTATION_HPP

namespace ft
{
    /*
     * In order iterator for binary search tree 
    */

    template <class T, class Compare, class Alloc>
    template <class Container, class Type>
    BinarySearchTree<
        T, Compare, Alloc
    >::template in_order_iterator<Container, Type>::in_order_iterator():
        m_container(NULL)
    {
    }

    template <class T, class Compare, class Alloc>
    template <class Container, class Type>
    BinarySearchTree<
        T, Compare, Alloc
    >::template in_order_iterator<Container, Type>::in_order_iterator(
        Container const &container
    ):
        m_container(container)
    {
    }

    template <class T, class Compare, class Alloc>
    template <class Container, class Type>
    template <class Container2, class Type2>
    BinarySearchTree<
        T, Compare, Alloc
    >::template in_order_iterator<Container, Type>::in_order_iterator(
        in_order_iterator<Container2, Type2> const &copy
    ):
        m_container(copy.base())
    {
    }

    template <class T, class Compare, class Alloc>
    template <class Container, class Type>
    BinarySearchTree<
        T, Compare, Alloc
    >::template in_order_iterator<Container, Type>::~in_order_iterator()
    {
    }

    template <class T, class Compare, class Alloc>
    template <class Container, class Type>
    typename BinarySearchTree<
        T, Compare, Alloc
    >::template in_order_iterator<Container, Type> &
    BinarySearchTree<
        T, Compare, Alloc
    >::template in_order_iterator<Container, Type>::operator=(
        in_order_iterator const &rhs
    )
    {
        if (this != &rhs)
        {
            m_container = rhs.base();
        }
        return *this;
    }

    template <class T, class Compare, class Alloc>
    template <class Container, class Type>
    Container BinarySearchTree<
        T, Compare, Alloc
    >::template in_order_iterator<Container, Type>::base() const
    {
        return m_container;
    }

    template <class T, class Compare, class Alloc>
    template <class Container, class Type>
    typename BinarySearchTree<
        T, Compare, Alloc
    >::template in_order_iterator<Container, Type>::reference
    BinarySearchTree<
        T, Compare, Alloc
    >::template in_order_iterator<Container, Type>::operator*() const
    {
        return m_container->data;
    }

    template <class T, class Compare, class Alloc>
    template <class Container, class Type>
    typename BinarySearchTree<
        T, Compare, Alloc
    >::template in_order_iterator<Container, Type>::pointer
    BinarySearchTree<
        T, Compare, Alloc
    >::template in_order_iterator<Container, Type>::operator->() const
    {
        return &m_container->data;
    }

    template <class T, class Compare, class Alloc>
    template <class Container, class Type>
    typename BinarySearchTree<
        T, Compare, Alloc
    >::template in_order_iterator<Container, Type> &
    BinarySearchTree<
        T, Compare, Alloc
    >::template in_order_iterator<Container, Type>::operator++()
    {
        increment();
        return *this;
    }

    template <class T, class Compare, class Alloc>
    template <class Container, class Type>
    typename BinarySearchTree<
        T, Compare, Alloc
    >::template in_order_iterator<Container, Type>
    BinarySearchTree<
        T, Compare, Alloc
    >::template in_order_iterator<Container, Type>::operator++(int)
    {
        in_order_iterator copy(*this);
        ++(*this);
        return copy;
    }

    template <class T, class Compare, class Alloc>
    template <class Container, class Type>
    void BinarySearchTree<
        T, Compare, Alloc
    >::template in_order_iterator<Container, Type>::increment()
    {
        // If parent and has right child
        if (m_container->rightChild)
        {
            // We reach end of left branch of right child
            m_container = m_container->rightChild;
            while (m_container->leftChild)
                m_container = m_container->leftChild;
        }
        else
        {
            // If we are right child of parent we ascend the branch
            Container parent = m_container->parent;
            while (parent && parent->rightChild == m_container)
            {
                m_container = parent;
                parent = m_container->parent;
            }
            if (parent != NULL && m_container->rightChild != parent)
                m_container = parent;
        }
    }

    template <class T, class Compare, class Alloc>
    template <class Container, class Type>
    typename BinarySearchTree<
        T, Compare, Alloc
    >::template in_order_iterator<Container, Type> &
    BinarySearchTree<
        T, Compare, Alloc
    >::template in_order_iterator<Container, Type>::operator--()
    {
        decrement();
        return *this;
    }

    template <class T, class Compare, class Alloc>
    template <class Container, class Type>
    typename BinarySearchTree<
        T, Compare, Alloc
    >::template in_order_iterator<Container, Type>
    BinarySearchTree<
        T, Compare, Alloc
    >::template in_order_iterator<Container, Type>::operator--(int)
    {
        in_order_iterator copy(*this);
        --(*this);
        return copy;
    }

    template <class T, class Compare, class Alloc>
    template <class Container, class Type>
    void BinarySearchTree<
        T, Compare, Alloc
    >::template in_order_iterator<Container, Type>::decrement()
    {
        // If Container has a left child
        if (m_container->leftChild)
        {
            // we reach end of right branch of left child
            m_container = m_container->leftChild;
            while (m_container->rightChild)
                m_container = m_container->rightChild;
        }
        else
        {
            // If we are left child of parent we ascend the branch
            Container parent = m_container->parent;
            while (parent && parent->leftChild == m_container)
            {
                m_container = parent;
                parent = m_container->parent;
            }
            if (parent && m_container->leftChild != parent)
                m_container = parent;
        }
    }
}

#endif
