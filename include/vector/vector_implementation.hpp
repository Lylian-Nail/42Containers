/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_implementation.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:22:15 by lperson-          #+#    #+#             */
/*   Updated: 2022/01/31 12:11:30 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_IMPLEMENTATION_HPP

#define VECTOR_IMPLEMENTATION_HPP

namespace ft
{

    /*
     * Ctors and dtor
    */

    template <class T, class Alloc>
    vector<T, Alloc>::vector(allocator_type const &alloc):
        m_alloc(alloc),
        m_size(0),
        m_capacity(0),
        m_values(NULL)
    {
    }

    template <class T, class Alloc>
    vector<T, Alloc>::vector(
        size_type size,
        value_type const &val,
        allocator_type const &alloc
    ):
        m_alloc(alloc),
        m_size(size),
        m_capacity(size)
    {
        m_values = m_alloc.allocate(m_capacity);
        for (size_type i(0); i < m_size; ++i)
            m_alloc.construct(m_values + i, val);
    }

    template <class T, class Alloc>
    template <class InputIterator>
    vector<T, Alloc>::vector(
        InputIterator first,
        InputIterator last,
        allocator_type const &alloc
    ):
        m_alloc(alloc)
    {
        difference_type size = ft::distance(first, last);
        m_size = size;
        m_capacity = size;
        m_values = m_alloc.allocate(m_capacity);
        for (int i(0); first != last; first++, ++i)
            m_alloc.construct(m_values + i, *first);
    }

    template <class T, class Alloc>
    vector<T, Alloc>::vector(vector const &copy):
        m_alloc(copy.get_allocator()),
        m_size(copy.size()),
        m_capacity(copy.capacity())
    {
        m_values = m_alloc.allocate(m_capacity);
        const_iterator first(copy.begin());
        const_iterator last(copy.end());
        for (size_type i(0); first != last; first++)
            m_alloc.construct(m_values + i, *first);
    }

    template <class T, class Alloc>
    vector<T, Alloc>::~vector()
    {
        iterator first(begin());
        iterator last(end());
        for (;first != last; first++)
            m_alloc.destroy(&*first);
        m_alloc.deallocate(m_values, m_capacity);
    }

    /*
     * Getters
    */

    template <class T, class Alloc>
    typename vector<T, Alloc>::size_type vector<T, Alloc>::size() const
    {
        return m_size;
    }

    template <class T, class Alloc>
    typename vector<T, Alloc>::size_type vector<T, Alloc>::capacity() const
    {
        return m_capacity;
    }

    template <class T, class Alloc>
    typename vector<T, Alloc>::allocator_type
        vector<T, Alloc>::get_allocator() const
    {
        return m_alloc;
    }

    /*
     Iterators
    */

    template <class T, class Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::begin()
    {
        return iterator(m_values);
    }

    template <class T, class Alloc>
    typename vector<T, Alloc>::const_iterator vector<T, Alloc>::begin() const
    {
        return const_iterator(m_values);
    }

    template <class T, class Alloc>
    typename vector<T, Alloc>::iterator vector<T, Alloc>::end()
    {
        return iterator(m_values + m_size);
    }

    template <class T, class Alloc>
    typename vector<T, Alloc>::const_iterator vector<T, Alloc>::end() const
    {
        return iterator(m_values + m_size);
    }

};

#endif