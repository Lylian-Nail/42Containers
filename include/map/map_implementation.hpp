/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_implementation.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:45:35 by lperson-          #+#    #+#             */
/*   Updated: 2022/04/08 12:50:13 by lperson-         ###   ########.fr       */
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

    template <class Key, class T, class Compare, class Alloc>
    template <class InputIterator>
    map<Key, T, Compare, Alloc>::map(
        typename enable_if<
            !is_integral<InputIterator>::value, InputIterator
        >::type first,
        InputIterator last,
        key_compare const &key_compare,
        allocator_type const &allocator
    ):
        m_key_compare(key_compare),
        m_value_compare(key_compare),
        m_tree(first, last, m_value_compare, allocator)
    {
    }

    template <class Key, class T, class Compare, class Alloc>
    map<Key, T, Compare, Alloc>::map(map const &copy):
        m_key_compare(copy.key_comp()),
        m_value_compare(copy.value_comp()),
        m_tree(copy.begin(), copy.end(), m_value_compare, copy.get_allocator())
    {
    }

    /*
     * Getters
    */

    template <class Key, class T, class Compare, class Alloc>
    bool map<Key, T, Compare, Alloc>::empty() const
    {
        return m_tree.empty();
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::size_type
    map<Key, T, Compare, Alloc>::size() const
    {
        return m_tree.size();
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::size_type
    map<Key, T, Compare, Alloc>::max_size() const
    {
        return m_tree.max_size();
    }

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

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::allocator_type
    map<Key, T, Compare, Alloc>::get_allocator() const
    {
        return m_tree.get_allocator();
    }

    /*
     * Iterators
    */

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::iterator
    map<Key, T, Compare, Alloc>::begin()
    {
        return m_tree.begin();
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::const_iterator
    map<Key, T, Compare, Alloc>::begin() const
    {
        return m_tree.begin();
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::iterator
    map<Key, T, Compare, Alloc>::end()
    {
        return m_tree.end();
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::const_iterator
    map<Key, T, Compare, Alloc>::end() const
    {
        return m_tree.end();
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::reverse_iterator
    map<Key, T, Compare, Alloc>::rbegin()
    {
        return m_tree.rbegin();
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::const_reverse_iterator
    map<Key, T, Compare, Alloc>::rbegin() const
    {
        return m_tree.rbegin();
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::reverse_iterator
    map<Key, T, Compare, Alloc>::rend()
    {
        return m_tree.rend();
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::const_reverse_iterator
    map<Key, T, Compare, Alloc>::rend() const
    {
        return m_tree.rend();
    }

    /*
     * Operators overload
    */

    template <class Key, class T, class Compare, class Alloc>
    map<Key, T, Compare, Alloc> &map<Key, T, Compare, Alloc>::operator=(
        map const &rhs
    )
    {
        if (this != &rhs)
        {
            m_key_compare = rhs.key_comp();
            m_value_compare = rhs.value_comp();
            m_tree = rhs.m_tree;
        }
        return *this;
    }
}

#endif
