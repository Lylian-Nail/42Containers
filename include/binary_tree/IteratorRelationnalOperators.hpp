/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IteratorRelationnalOperators.hpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:01:20 by lperson-          #+#    #+#             */
/*   Updated: 2022/03/17 13:08:56 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_RELATIONNAL_OPERATORS_HPP

# define ITERATOR_RELATIONNAL_OPERATORS_HPP

namespace ft
{
    /*
     * Create CRTP base class to implements relationnal operators for
     * nested class iterators.
     * Its resolves nested class template deduction failure
    */

    template <class Derived>
    struct IteratorRelationnalOperator 
    {
    };

    template <class Node>
    bool operator==(
        IteratorRelationnalOperator<Node> const &it0,
        IteratorRelationnalOperator<Node> const &it1
    )
    {
        Node const &it0Impl = static_cast<Node const &>(it0);
        Node const &it1Impl = static_cast<Node const &>(it1);
        return it0Impl.base() == it1Impl.base();
    }

    template <class Node0, class Node1>
    bool operator==(
        IteratorRelationnalOperator<Node0> const &it0,
        IteratorRelationnalOperator<Node1> const &it1
    )
    {
        Node0 const &it0Impl = static_cast<Node0 const &>(it0);
        Node1 const &it1Impl = static_cast<Node1 const &>(it1);
        return it0Impl.base() == it1Impl.base();
    }

    template <class Node>
    bool operator!=(
        IteratorRelationnalOperator<Node> const &it0,
        IteratorRelationnalOperator<Node> const &it1
    )
    {
        Node const &it0Impl = static_cast<Node const &>(it0);
        Node const &it1Impl = static_cast<Node const &>(it1);
        return it0Impl.base() != it1Impl.base();
    }

    template <class Node0, class Node1>
    bool operator!=(
        IteratorRelationnalOperator<Node0> const &it0,
        IteratorRelationnalOperator<Node1> const &it1
    )
    {
        Node0 const &it0Impl = static_cast<Node0 const &>(it0);
        Node1 const &it1Impl = static_cast<Node1 const &>(it1);
        return it0Impl.base() == it1Impl.base();
    }
}

#endif