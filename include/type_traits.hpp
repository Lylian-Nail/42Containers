/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:09:02 by lperson-          #+#    #+#             */
/*   Updated: 2022/02/21 14:18:23 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP

# define TYPE_TRAITS_HPP

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
     * Check if type is integral
    */

    template <class T>
    struct is_integral : public false_type {};

    template <class T>
    struct is_integral<const T> : public is_integral<T> {};

    template <class T>
    struct is_integral<volatile T> : public is_integral<T> {};

    template <class T>
    struct is_integral<volatile const T> : public is_integral<T> {};

    template <>
    struct is_integral<bool> : public true_type {};

    template <>
    struct is_integral<char> : public true_type {};

    template <>
    struct is_integral<wchar_t> : public true_type {};

    template <>
    struct is_integral<signed char> : public true_type {};

    template <>
    struct is_integral<short int> : public true_type {};

    template <>
    struct is_integral<int> : public true_type {};

    template <>
    struct is_integral<long int> : public true_type {};

    template <>
    struct is_integral<long long int> : public true_type {};

    template <>
    struct is_integral<unsigned char> : public true_type {};

    template <>
    struct is_integral<unsigned short int> : public true_type {};

    template <>
    struct is_integral<unsigned int> : public true_type {};

    template <>
    struct is_integral<unsigned long int> : public true_type {};

    template <>
    struct is_integral<unsigned long long int> : public true_type {};

    /*
     * Check compile time enable_if
    */

    template <bool B, class T = void>
    struct enable_if {};

    template <class T>
    struct enable_if<true, T> : public type_identity<T> {};

}

#endif
