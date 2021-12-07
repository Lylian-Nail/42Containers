/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:43:45 by lperson-          #+#    #+#             */
/*   Updated: 2021/12/07 12:05:12 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP

# define VECTOR_HPP

# include <memory>
# include "iterators/normal_iterator.hpp"

namespace ft
{

    template <class T, class Alloc = std::allocator<T> >
    class vector
    {
    public:

        /*
         * Defines aliases of vector
        */

        typedef T                                           value_type;
        typedef Alloc                                       allocator_type;
        typedef typename allocator_type::reference          reference;
        typedef typename allocator_type::const_reference    const_reference;
        typedef typename allocator_type::pointer            pointer;
        typedef typename allocator_type::const_pointer      const_pointer;
        typedef NormalIterator<pointer, vector>             iterator;
        typedef NormalIterator<const_pointer, vector>       const_iterator;
        typedef std::reverse_iterator<iterator>             reverse_iterator;
        typedef std::reverse_iterator<const_iterator>       
                                                    const_reverse_iterator;
        typedef typename std::iterator_traits<iterator>::difference_type
                                                    difference_type;
        typedef size_t                                      size_type;


        /*
         * Ctors
        */

        explicit vector(void);
        explicit vector(size_type n, value_type const &val);
        template <class InputIterator>
        vector(InputIterator first, InputIterator last);
        vector(vector const &copy);

        /*
         * Getters
        */

        allocator_type  get_allocator() const;
        size_type       size() const;
        size_type       max_size() const;

    private:
        const_pointer   _datas;
        allocator_type  _allocator;
        size_type       _size;
        size_type       _capacity;
    };

};

# include "vector/vector_implementation.tpp"

#endif
