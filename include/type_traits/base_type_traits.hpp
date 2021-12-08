/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_type_traits.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:10:10 by lperson-          #+#    #+#             */
/*   Updated: 2021/12/08 14:57:29 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_TYPE_TRAITS_HPP

#define BASE_TYPE_TRAITS_HPP

namespace ft
{
    /*
     * Defines TypeIdentity meta function to contains types
     * usefull for future type traits meta functions
     */
    template <class T>
    struct type_identity
    {
        typedef T type;
    };

    /*
     * Defines integral constant meta function value
     */
    template <class T, T Value>
    struct integral_constant
    {
        static const T value = Value;

        typedef T value_type;
        typedef integral_constant<T, Value> type;

        operator value_type() const { return value; }
        const value_type operator()() const { return value; }
    };

    /*
     * Defines 2 specific integral constant for booleans
     */
    typedef integral_constant<bool, true> true_type;
    typedef integral_constant<bool, false> false_type;
}

#endif
