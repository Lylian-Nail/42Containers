/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinarySearchTree_in_order_iterator_definiti        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:28:33 by lperson-          #+#    #+#             */
/*   Updated: 2022/04/12 16:06:51 by lperson-         ###   ########.fr       */
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
    template <class Container, class Type>
    class BinarySearchTree<T, Compare, Alloc>::in_order_iterator :
        public IteratorRelationnalOperator<in_order_iterator<Container, Type> >
    {
    public:
        typedef typename std::bidirectional_iterator_tag
                                                iterator_category;
        typedef typename iterator_traits<Container>::difference_type
                                                difference_type;
        typedef typename iterator_traits<Type>::value_type
                                                value_type;
        typedef typename iterator_traits<Type>::pointer
                                                pointer;
        typedef typename iterator_traits<Type>::reference
                                                reference;

        in_order_iterator();
        in_order_iterator(Container const &container);
        template <class Container2, class Type2>
        in_order_iterator(in_order_iterator<Container2, Type2> const &copy);
        ~in_order_iterator();

        in_order_iterator &operator=(in_order_iterator const &rhs);

        /*
            * Getter
        */

        Container base() const;

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
        Container    m_container;

        void increment();
        void decrement();
    };
}
#endif
