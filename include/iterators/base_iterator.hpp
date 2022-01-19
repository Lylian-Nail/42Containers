/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:07:42 by lperson-          #+#    #+#             */
/*   Updated: 2021/12/07 15:41:18 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_ITERATOR_HPP

# define BASE_ITERATOR_HPP

namespace ft
{
    /*
     * Iterator tags to differentiate iterators between them.
     * We use inheritance to use polymorphism in algo
    */

    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag : public input_iterator_tag {};
    struct bidirectional_iterator_tag : public forward_iterator_tag {};
    struct random_access_iterator_tag : public bidirectional_iterator_tag {};

    /*
     * This class defines iterator traits for any iterators
     * This does not implement anything but give helps for generates iterators
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
}

#endif
