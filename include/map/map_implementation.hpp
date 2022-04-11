/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_implementation.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:45:35 by lperson-          #+#    #+#             */
/*   Updated: 2022/04/11 15:23:46 by lperson-         ###   ########.fr       */
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

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::size_type
    map<Key, T, Compare, Alloc>::count(key_type const &key) const
    {
        return m_tree.count(
            ft::make_pair<key_type const, mapped_type const>(key, mapped_type())
        );
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::const_iterator
    map<Key, T, Compare, Alloc>::find(key_type const &key) const
    {
        return m_tree.find(
            ft::make_pair<key_type const, mapped_type const>(key, mapped_type())
        );
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::const_iterator
    map<Key, T, Compare, Alloc>::lower_bound(key_type const &key) const
    {
        return m_tree.lower_bound(
            ft::make_pair<key_type const, mapped_type const>(key, mapped_type())
        );
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::const_iterator
    map<Key, T, Compare, Alloc>::upper_bound(key_type const &key) const
    {
        return m_tree.upper_bound(
            ft::make_pair<key_type const, mapped_type const>(key, mapped_type())
        );
    }

    template <class Key, class T, class Compare, class Alloc>
    ft::pair<
        typename map<Key, T, Compare, Alloc>::const_iterator,
        typename map<Key, T, Compare, Alloc>::const_iterator
    > map<Key, T, Compare, Alloc>::equal_range(key_type const &key) const
    {
        return m_tree.equal_range(
            ft::make_pair<key_type const, mapped_type const>(key, mapped_type())
        );
    }

    /*
     * Setters
    */

    template <class Key, class T, class Compare, class Alloc>
    ft::pair<typename map<Key, T, Compare, Alloc>::iterator, bool>
    map<Key, T, Compare, Alloc>::insert(const_reference value)
    {
        return m_tree.insert(value);
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::iterator
    map<Key, T, Compare, Alloc>::insert(
        iterator position, const_reference value
    )
    {
        return m_tree.insert(position, value);
    }

    template <class Key, class T, class Compare, class Alloc>
    template <class InputIterator>
    void map<Key, T, Compare, Alloc>::insert(
        typename enable_if<
            !is_integral<InputIterator>::value, InputIterator
        >::type first,
        InputIterator last
    )
    {
        return m_tree.insert(first, last);
    }

    template <class Key, class T, class Compare, class Alloc>
    void map<Key, T, Compare, Alloc>::erase(iterator position)
    {
        m_tree.erase(position);
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::size_type
    map<Key, T, Compare, Alloc>::erase(key_type const &key)
    {
        return m_tree.erase(
            ft::make_pair(key, mapped_type())
        );
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::iterator
    map<Key, T, Compare, Alloc>::find(key_type const &key)
    {
        return m_tree.find(
            ft::make_pair<const key_type, mapped_type>(key, mapped_type())
        );
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::iterator
    map<Key, T, Compare, Alloc>::lower_bound(key_type const &key)
    {
        return m_tree.lower_bound(
            ft::make_pair<key_type const, mapped_type>(key, mapped_type())
        );
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::iterator
    map<Key, T, Compare, Alloc>::upper_bound(key_type const &key)
    {
        return m_tree.upper_bound(
            ft::make_pair<key_type const, mapped_type>(key, mapped_type())
        );
    }

    template <class Key, class T, class Compare, class Alloc>
    ft::pair<
        typename map<Key, T, Compare, Alloc>::iterator,
        typename map<Key, T, Compare, Alloc>::iterator
    > map<Key, T, Compare, Alloc>::equal_range(key_type const &key)
    {
        return m_tree.equal_range(
            ft::make_pair<key_type const, mapped_type>(key, mapped_type())
        );
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
