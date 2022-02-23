/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_definition.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:23:43 by lperson-          #+#    #+#             */
/*   Updated: 2022/02/23 14:56:40 by lperson-         ###   ########.fr       */
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
        bool empty() const;
        size_type capacity() const;
        size_type max_size() const;
        allocator_type get_allocator() const;
        reference operator[](size_type n);
        const_reference operator[](size_type n) const;
        reference at(size_type n);
        const_reference at(size_type n) const;
        reference front();
        const_reference front() const;
        reference back();
        const_reference back() const;

        /*
         * Setters
        */

        void reserve(size_type capacity);
        void resize(size_type size, value_type value = value_type());
        void push_back(value_type const &value);
        void pop_back();
        void clear();
        template <class InputIterator>
        void assign(
            typename enable_if<
                !is_integral<InputIterator>::value, InputIterator
            >::type first,
            InputIterator last
        );
        void assign(size_type n, value_type const &value);
        iterator insert(iterator position, value_type const &value);
        void insert(iterator position, size_type size, value_type const &value);
        template <class InputIterator>
        void insert(
            iterator position,
            typename enable_if<
                !is_integral<InputIterator>::value, InputIterator
            >::type first,
            InputIterator last
        );
        iterator erase(iterator position);
        iterator erase(iterator first, iterator last);

        /*
         * Copy and swap
        */

        vector &operator=(vector const &vectorCopied);
        void swap(vector &vectorSwapped);

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

    /*
     * Non-members functions
    */

    template <class T, class Alloc>
    void swap(vector<T, Alloc> &first, vector<T, Alloc> &second);

    /*
     * Non-members functions relationnal operators
    */

    template <class T, class Alloc>
    bool operator==(vector<T, Alloc> const &lhs, vector<T, Alloc> const &rhs);
    template <class T, class Alloc>
    bool operator!=(vector<T, Alloc> const &lhs, vector<T, Alloc> const &rhs);
    template <class T, class Alloc>
    bool operator<(vector<T, Alloc> const &lhs, vector<T, Alloc> const &rhs);

};

#endif
