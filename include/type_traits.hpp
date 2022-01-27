/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:09:02 by lperson-          #+#    #+#             */
/*   Updated: 2022/01/27 12:27:48 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP

# define TYPE_TRAITS_HPP

# include <iterator.hpp>
# include "type_traits/base_type_traits.hpp"

namespace ft
{

    /*
     * Check if same types
    */

    template <class T, class U>
    struct is_same : public false_type {};

    template <class T>
    struct is_same<T, T> : public true_type {};

    /*
     * Delete const qualifier
    */

    template <class T>
    struct remove_const : public type_identity<T> {};

    template <class T>
    struct remove_const<T const> : public type_identity<T> {};

    /*
     * Delete const volatile qualifiers
    */

    template <class T>
    struct remove_cv : public type_identity<typename remove_const<T>::type> {};

    template <class T>
    struct remove_cv<volatile T> : public type_identity<
        typename remove_const<T>::type
    >
    {
    };

    /*
     * Check compile time enable_if
    */

    template <bool B, class T = void>
    struct enable_if {};

    template <class T>
    struct enable_if<true, T> : public type_identity<T> {};

}

#endif
