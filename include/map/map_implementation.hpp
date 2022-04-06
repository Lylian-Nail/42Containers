/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_implementation.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:45:35 by lperson-          #+#    #+#             */
/*   Updated: 2022/04/06 12:36:00 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_IMPLEMENTATION_HPP

# define MAP_IMPLEMENTATION_HPP

namespace ft
{
    /*
     * Constructors and destructor
    */

    template <class Key, class T, class Compare, class Alloc>
    map<Key, T, Compare, Alloc>::map(
        key_compare const &key_compare, allocator_type const &allocator
    ):
        m_key_compare(key_compare),
        m_value_compare(key_compare),
        m_tree(m_value_compare, allocator)
    {
    }

    /*
     * Getters
    */

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::key_compare
    map<Key, T, Compare, Alloc>::key_comp() const
    {
        return m_key_compare;
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::value_compare
    map<Key, T, Compare, Alloc>::value_comp() const
    {
        return m_tree.value_comp();
    }
}

#endif
