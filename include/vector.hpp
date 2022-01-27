/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:10:41 by lperson-          #+#    #+#             */
/*   Updated: 2022/01/27 15:13:51 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP

# define VECTOR_HPP

# include <memory>
# include "iterator.hpp"

namespace ft
{

    template <class T, class Alloc = std::allocator<T> >
    class Vector
    {

        typedef T                                           value_type;
        typedef Alloc                                       allocator_type;
        typedef typename allocator_type::reference          reference;
        typedef typename allocator_type::const_reference    const_reference;
        typedef typename allocator_type::pointer            pointer;
        typedef typename allocator_type::const_pointer      const_pointer;
        typedef ft::normal_iterator<pointer, Vector>        iterator;
        typedef ft::normal_iterator<const_pointer, Vector>  const_iterator;
        typedef ft::reverse_iterator<iterator>              reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>        
            const_reverse_iterator;
        typedef typename ft::iterator_traits<iterator>::difference_type
            difference_type;
        typedef std::size_t                                 size_type;
    };

};

#endif
