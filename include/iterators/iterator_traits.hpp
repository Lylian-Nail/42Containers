/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:09:25 by lperson-          #+#    #+#             */
/*   Updated: 2022/04/12 15:59:09 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP

# define ITERATOR_TRAITS_HPP

/*
 * The purpose of iterator_trait is to extract the traits of an iterator
 * or a pointer. (As a pointer behavior the same way as an iterator).
 */

namespace ft
{

    /*
     * This class get iterator traits from iterator
    */

    template <class Iterator>
    struct iterator_traits : public iterator<
        typename Iterator::iterator_category,
        typename Iterator::value_type
    >
    {};

    /*
     * Or from pointers
    */

    template <class T> class iterator_traits<T*> : public iterator<
        std::random_access_iterator_tag,
        T
    >
    {};

    /*
     * Or from const pointers
    */

   template <class T> class iterator_traits<T const *> : public iterator<
        std::random_access_iterator_tag,
        T const,
        ptrdiff_t,
        T const *,
        T const &
   >
   {};
}

#endif
