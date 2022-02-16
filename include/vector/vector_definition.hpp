/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_definition.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:23:43 by lperson-          #+#    #+#             */
/*   Updated: 2022/02/16 13:30:10 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_DEFINITION_HPP

# define VECTOR_DEFINITION_HPP

# include "iterator.hpp"
# include "type_traits.hpp"
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
            typename enable_if<
                !is_integral<InputIterator>::value, InputIterator
            >::type first,
            InputIterator last,
            allocator_type const &alloc = allocator_type()
        );
        vector(vector const &copy);
        ~vector();

        /*
         * Getters
        */

        size_type size() const;
        size_type capacity() const;
        allocator_type get_allocator() const;
        reference operator[](size_type n);
        const_reference operator[](size_type n) const;
        reference at(size_type n);
        const_reference at(size_type n) const;

        /*
         * Iterators
        */

        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;
        reverse_iterator rbegin();
        const_reverse_iterator rbegin() const;
        reverse_iterator rend();
        const_reverse_iterator rend() const;

    private:
        allocator_type  m_alloc;
        size_type       m_size;
        size_type       m_capacity;
        pointer         m_values;

    };

};

#endif
