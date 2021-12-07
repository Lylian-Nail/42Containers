/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:09:25 by lperson-          #+#    #+#             */
/*   Updated: 2021/12/07 15:10:21 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP

# define ITERATOR_TRAITS_HPP

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
