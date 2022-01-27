/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 13:10:41 by lperson-          #+#    #+#             */
/*   Updated: 2022/01/27 13:28:08 by lperson-         ###   ########.fr       */
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
        typedef T &                                         reference;
        typedef T const &                                   const_reference;
        typedef T *                                         pointer;
        typedef T const *                                   const_pointer;
        typedef ft::normal_iterator<pointer, Vector>        iterator;
        typedef ft::normal_iterator<const_pointer, Vector>  const_iterator;
        typedef ft::reverse_iterator<iterator>              reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>        
            const_reverse_iterator;
        typedef std::size_t                                 size_type;
        typedef ptrdiff_t                                   difference_type;
    };

};

#endif
