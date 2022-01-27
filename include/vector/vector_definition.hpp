/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_definition.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:23:43 by lperson-          #+#    #+#             */
/*   Updated: 2022/01/27 16:18:01 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_DEFINITION_HPP

# define VECTOR_DEFINITION_HPP

# include "iterator.hpp"
# include <memory>

namespace ft
{

    template <class T, class Alloc = std::allocator<T> >
    class vector
    {
    public:
        /*
         * Typedefs members
        */

        typedef T                                           value_type;
        typedef Alloc                                       allocator_type;
        typedef typename allocator_type::reference          reference;
        typedef typename allocator_type::const_reference    const_reference;
        typedef typename allocator_type::pointer            pointer;
        typedef typename allocator_type::const_pointer      const_pointer;
        typedef ft::normal_iterator<pointer, vector>        iterator;
        typedef ft::normal_iterator<const_pointer, vector>  const_iterator;
        typedef ft::reverse_iterator<iterator>              reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>        
            const_reverse_iterator;
        typedef typename ft::iterator_traits<iterator>::difference_type
            difference_type;
        typedef std::size_t                                 size_type;

        /*
         * Ctors and dtor
        */

        explicit vector(allocator_type const &alloc = allocator_type());
        explicit vector(
            size_type n,
            value_type const &val = value_type(),
            allocator_type const &alloc = allocator_type()
        );
        template <class InputIterator>
        vector(
            InputIterator first, InputIterator last, allocator_type const &alloc = allocator_type()
        );
        vector(vector const &copy);
        ~vector();


        /*
         * Getters
        */

        size_type size() const;
        size_type capacity() const;
        allocator_type get_allocator() const;

        /*
         * Iterators
        */

        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;

    private:
        allocator_type  m_alloc;
        size_type       m_size;
        size_type       m_capacity;
        value_type      m_values[];

    };

    /*
     * Ctors and dtor
    */

    template <class T, class Alloc = std::allocator<T> >
    vector::vector(allocator_type const &alloc):
        m_alloc(alloc),
        m_size(0),
        m_capacity(0),
        m_values(NULL),
    {
    }

    template <class T, class Alloc = std::allocator<T> >
    vector::vector(
        size_type size,
        value_type const &val,
        allocator_type const &alloc
    ):
        m_alloc(alloc),
        m_size(n),
        m_capacity(n)
    {
        m_values = m_alloc.allocate(m_capacity);
        for (size_type i(0); i < m_size; ++i)
            m_alloc.construct(m_values + i, val);
    }

    template <class T, class Alloc = std::allocator<T>, class InputIterator>
    vector::vector(
        InputIterator first,
        InputIterator last,
        allocator_type const &alloc
    ):
        m_alloc(alloc)
    {
        difference_type size = ft::distance(first, last);
        m_size = size;
        m_storage_size = size;
        m_values = m_alloc.allocate(m_capacity);
        for (; first != last; first++)
            m_alloc.construct(m_values + i, *first);
    }

    template <class T, class Alloc = std::allocator<T> >
    vector::vector(vector const &copy):
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

    template <class T, class Alloc = std::allocator<T> >
    vector::~vector()
    {
        iterator first(begin());
        iterator last(end());
        for (;first != last; first++)
            m_alloc.destroy(*first);
        m_alloc.deallocate(m_values, m_capacity);
    }

    /*
     * Getters
    */

    template <class T, class Alloc = std::allocator<T> >
    size_type vector::size() const
    {
        return m_size;
    }

    template <class T, class Alloc = std::allocator<T> >
    size_type vector::capacity() const
    {
        return m_capacity;
    }

    template <class T, class Alloc = std::allocator<T> >
    allocator_type get_allocator() const
    {
        return m_alloc;
    }

    /*
     Iterators
    */

    template <class T, class Alloc = std::allocator<T> >
    iterator vector::begin()
    {
        return iterator(m_values);
    }

    template <class T, class Alloc = std::allocator<T> >
    const_iterator vector::begin() const
    {
        return const_iterator(m_values);
    }

    template <class T, class Alloc = std::allocator<T> >
    iterator vector::end()
    {
        return iterator(m_values + m_size);
    }

    template <class T, class Alloc = std::allocator<T> >
    iterator vector::end() const
    {
        return iterator(m_values + m_size);
    }

};

#endif
