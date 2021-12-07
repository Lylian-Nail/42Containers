/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:08:20 by lperson-          #+#    #+#             */
/*   Updated: 2021/12/07 12:45:14 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP

# define ITERATOR_HPP

# include <cstddef>

namespace ft
{

    /*
     * Iterator tags to differentiates iterators between them
    */

    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag {};
    struct bidirectional_iterator_tag {};
    struct random_access_iterator_tag {};

    /*
     * This class defines iterator traits for any iterators
     * This does not implement anythings
    */

    template <
        class Category, class T, class Distance = ptrdiff_t,
        class Pointer = T*, class Reference = T&
    >
    struct iterator
    {
        typedef T           value_type;
        typedef Distance    difference_type;
        typedef Pointer     pointer;
        typedef Reference   reference;
        typedef Category    iterator_category;
    };


    /*
     * This class get iterator traits from iterator
    */

    template <class Iterator>
    struct iterator_traits : public iterator<
        typename Iterator::iterator_category,
        typename Iterator::value_type,
    >
    {};

    /*
     * Or from pointers
    */

    template <class T> class iterator_traits<T*> : public iterator<
        random_access_iterator_tag,
        T
    >
    {};

    /*
     * Or from const pointers
    */

   template <class T> class iterator_traits<T const *> : public iterator<
        random_access_iterator_tag,
        T const,
        ptrdiff_t,
        T const *,
        T const &
   >
   {};

}

#endif
