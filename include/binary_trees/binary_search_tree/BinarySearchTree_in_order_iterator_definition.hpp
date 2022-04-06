/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinarySearchTree_in_order_iterator_definiti        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:28:33 by lperson-          #+#    #+#             */
/*   Updated: 2022/04/05 11:13:06 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_SEARCH_TREE_IN_ORDER_ITERATOR_DEFINITION_HPP

# define BINARY_SEARCH_TREE_IN_ORDER_ITERATOR_DEFINITION_HPP

# include "iterator.hpp"

namespace ft
{
    /*
     * Create an iterator for binary search tree class
    */

    template <class T, class Compare, class Alloc>
    template <class Node, class Type>
    class BinarySearchTree<T, Compare, Alloc>::in_order_iterator :
        public IteratorRelationnalOperator<in_order_iterator<Node, Type> >
    {
    public:
        typedef typename std::bidirectional_iterator_tag
                                                iterator_category;
        typedef typename iterator_traits<Node>::difference_type
                                                difference_type;
        typedef typename iterator_traits<Type>::value_type
                                                value_type;
        typedef typename iterator_traits<Type>::pointer
                                                pointer;
        typedef typename iterator_traits<Type>::reference
                                                reference;

        in_order_iterator();
        in_order_iterator(Node const &node);
        template <class Node2, class Type2>
        in_order_iterator(in_order_iterator<Node2, Type2> const &copy);
        ~in_order_iterator();

        in_order_iterator &operator=(in_order_iterator const &rhs);

        /*
            * Getter
        */

        Node base() const;

        /*
            * Forward iterator spec
        */

        reference operator*() const;
        pointer operator->() const;

        in_order_iterator &operator++();
        in_order_iterator operator++(int);

        /*
            * Bidirectional iterator spec
        */

        in_order_iterator &operator--();
        in_order_iterator operator--(int);

    private:
        Node    m_node;

        void increment();
        void decrement();
    };
}
#endif