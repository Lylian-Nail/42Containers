/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_implementation.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:22:15 by lperson-          #+#    #+#             */
/*   Updated: 2022/02/22 11:39:39 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_IMPLEMENTATION_HPP

# define VECTOR_IMPLEMENTATION_HPP

# include <stdexcept>
# include "type_traits.hpp"
# include <stdexcept>

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
        m_size(0),
        m_capacity(0),
        m_values(NULL)
    {
        this->assign(size, val);
    }

    template <class T, class Alloc>
    template <class InputIterator>
    vector<T, Alloc>::vector(
        typename enable_if<
            !is_integral<InputIterator>::value, InputIterator
        >::type first,
        InputIterator last,
        allocator_type const &alloc
    ):
        m_alloc(alloc),
        m_size(0),
        m_capacity(0),
        m_values(NULL)
    {
        this->assign(first, last);
    }

    template <class T, class Alloc>
    vector<T, Alloc>::vector(vector const &copy):
        m_alloc(copy.get_allocator()),
        m_size(0),
        m_capacity(0),
        m_values(NULL)
    {
        *this = copy;
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
    bool vector<T, Alloc>::empty() const
    {
        return size() == 0;
    }

    template <class T, class Alloc>
    typename vector<T, Alloc>::size_type vector<T, Alloc>::capacity() const
    {
        return m_capacity;
    }

    template <class T, class Alloc>
    typename vector<T, Alloc>::size_type vector<T, Alloc>::max_size() const
    {
        return m_alloc.max_size();
    }

    template <class T, class Alloc>
    typename vector<T, Alloc>::allocator_type
        vector<T, Alloc>::get_allocator() const
    {
        return m_alloc;
    }

    template <class T, class Alloc>
    typename vector<T, Alloc>::reference
        vector<T, Alloc>::operator[](size_type n)
    {
        return m_values[n];
    }

    template <class T, class Alloc>
    typename vector<T, Alloc>::const_reference
        vector<T, Alloc>::operator[](size_type n) const
    {
        return m_values[n];
    }

    template <class T, class Alloc>
    typename vector<T, Alloc>::reference vector<T, Alloc>::at(size_type n)
    {
        if (n >= size())
            throw std::out_of_range("vector::at");
        return m_values[n];
    }

    template <class T, class Alloc>
    typename vector<T, Alloc>::const_reference
        vector<T, Alloc>::at(size_type n) const
    {
        if (n >= size())
            throw std::out_of_range("vector::at");
        return m_values[n];
    }

    template <class T, class Alloc>
    typename vector<T, Alloc>::reference vector<T, Alloc>::front()
    {
        return *m_values;
    }

    template <class T, class Alloc>
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::front() const
    {
        return *m_values;
    }

    template <class T, class Alloc>
    typename vector<T, Alloc>::reference vector<T, Alloc>::back()
    {
        return m_values[m_size - 1];
    }

    template <class T, class Alloc>
    typename vector<T, Alloc>::const_reference vector<T, Alloc>::back() const
    {
        return m_values[m_size - 1];
    }

    /*
     * Setters
    */

    template <class T, class Alloc>
    void vector<T, Alloc>::reserve(
        typename vector<T, Alloc>::size_type capacity
    )
    {
        if (capacity > max_size())
            throw (std::length_error("reserve"));
        else if (capacity > m_capacity)
        {
            size_type new_capacity = m_capacity > 1 ? m_capacity : capacity;
            while (new_capacity < capacity)
                new_capacity *= 1.5;

            pointer new_values = m_alloc.allocate(new_capacity);
            const_iterator first(begin());
            const_iterator last(end());
            for (size_type i(0); first != last; first++, i++)
            {
                m_alloc.construct(new_values + i, *first);
                m_alloc.destroy(m_values + i);
            }
            m_alloc.deallocate(m_values, m_capacity);

            m_values = new_values;
            m_capacity = new_capacity;
        }
    }

    template <class T, class Alloc>
    void vector<T, Alloc>::resize(size_type size, value_type value)
    {
        if (size > m_size)
        {
            if (size > m_capacity)
                this->reserve(size);
            for (; m_size < size; m_size++)
                m_alloc.construct(m_values + m_size, value);
        }
        else
        {
            for (size_type i = size; i < m_size; i++)
                m_alloc.destroy(m_values + i);
            m_size = size;
        }
    }

    template <class T, class Alloc>
    void vector<T, Alloc>::push_back(value_type const &value)
    {
        this->resize(m_size + 1, value);
    }

    template <class T, class Alloc>
    void vector<T, Alloc>::pop_back()
    {
        this->resize(m_size - 1);
    }

    template <class T, class Alloc>
    void vector<T, Alloc>::clear()
    {
        this->resize(0);
    }

    template <class T, class Alloc>
    template <class InputIterator>
    void vector<T, Alloc>::assign(
        typename enable_if<
            !is_integral<InputIterator>::value, InputIterator
        >::type first,
        InputIterator last
    )
    {
        this->clear();

        size_type size = distance(first, last);
        if (size > m_capacity)
            this->reserve(size);

        for (size_type i(0); first != last; first++, ++i)
            m_alloc.construct(m_values + i, *first);
        m_size = size;
    }

    template <class T, class Alloc>
    void vector<T, Alloc>::assign(
        size_type n, value_type const &value
    )
    {
        this->clear();
        this->resize(n, value);
    }

    template <class T, class Alloc>
    typename vector<T, Alloc>::iterator
    vector<T, Alloc>::erase(iterator position)
    {
        const_iterator last = this->end();
        iterator first = position;
        m_alloc.destroy(&(*position));
        for (;first != last; first++)
            first[0] = first[1];
        m_size--;
        return position;
    }

    template <class T, class Alloc>
    typename vector<T, Alloc>::iterator
    vector<T, Alloc>::erase(iterator first, iterator last)
    {
        iterator oldPos = first;
        size_type offset = 0;
        iterator newPos = first;
        for (; first != last; first++, offset++)
        {
            m_alloc.destroy(&(*first));
        }
        iterator end = this->end();
        for (; last != end; last++)
        {
            *(last - offset) = *last;
        }
        m_size -= offset;

        return newPos;
    }

    /*
     * Copy and swap
    */

    template <class T, class Alloc>
    vector<T, Alloc> &vector<T, Alloc>::operator=(
        vector const &vectorCopied
    )
    {
        if (this != &vectorCopied)
        {
            this->assign(vectorCopied.begin(), vectorCopied.end());
        }
        return *this;
    }

    template <class T, class Alloc>
    void vector<T, Alloc>::swap(vector &vectorSwapped)
    {
        if (this != &vectorSwapped)
        {
            vector<T, Alloc>::pointer values = vectorSwapped.m_values;
            vector<T, Alloc>::size_type size = vectorSwapped.size();
            vector<T, Alloc>::size_type capacity = vectorSwapped.capacity();
            vector<T, Alloc>::allocator_type allocator;
            allocator = vectorSwapped.get_allocator();

            vectorSwapped.m_values = m_values;
            vectorSwapped.m_size = this->size();
            vectorSwapped.m_capacity = this->capacity();
            vectorSwapped.m_alloc = this->get_allocator();

            m_values = values;
            m_size = size;
            m_capacity = capacity;
            m_alloc = allocator;
        }
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
        return const_iterator(m_values + m_size);
    }

    template <class T, class Alloc>
    typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rbegin()
    {
        return reverse_iterator(end());
    }

    template <class T, class Alloc>
    typename vector<T, Alloc>::const_reverse_iterator
    vector<T, Alloc>::rbegin() const
    {
        return reverse_iterator(end());
    }

    template <class T, class Alloc>
    typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rend()
    {
        return reverse_iterator(begin());
    }

    template <class T, class Alloc>
    typename vector<T, Alloc>::const_reverse_iterator
    vector<T, Alloc>::rend() const
    {
        return reverse_iterator(begin());
    }

    /*
     * Non-members function
    */

    template <class T, class Alloc>
    void swap(vector<T, Alloc> &first, vector<T, Alloc> &second)
    {
        first.swap(second);
    }

};

#endif