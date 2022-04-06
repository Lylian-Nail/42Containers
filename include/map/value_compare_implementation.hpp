/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_compare_implementation.hpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:32:24 by lperson-          #+#    #+#             */
/*   Updated: 2022/04/06 12:41:38 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{
    template <class Key, class T, class Compare, class Alloc>
    map<Key, T, Compare, Alloc>::value_compare::value_compare()
    {
    }

    template <class Key, class T, class Compare, class Alloc>
    map<Key, T, Compare, Alloc>::value_compare::value_compare(Compare comp):
        m_comp(comp)
    {
    }

    template <class Key, class T, class Compare, class Alloc>
    map<Key, T, Compare, Alloc>::value_compare::value_compare(
        value_compare const &
    )
    {
    }

    template <class Key, class T, class Compare, class Alloc>
    map<Key, T, Compare, Alloc>::value_compare::~value_compare()
    {
    }

    template <class Key, class T, class Compare, class Alloc>
    bool map<Key, T, Compare, Alloc>::value_compare::operator()(
        value_type const &lhs, value_type const &rhs
    ) const
    {
        return m_comp(lhs.first, rhs.first);
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::value_compare &
    map<Key, T, Compare, Alloc>::value_compare::operator=(
        value_compare const &
    )
    {
    }
}
