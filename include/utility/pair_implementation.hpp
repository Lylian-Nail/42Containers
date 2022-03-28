/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair_implementation.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 07:49:46 by lperson-          #+#    #+#             */
/*   Updated: 2022/03/28 07:57:04 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_IMPLEMENTATION_HPP

# define PAIR_IMPLEMENTATION_HPP

namespace ft
{

    template <class T1, class T2>
    pair<T1, T2>::pair():
        first(),
        second()
    {
    }

    template <class T1, class T2>
    template <class U, class V>
    pair<T1, T2>::pair(pair<U, V> const &copy):
        first(copy.first),
        second(copy.second)
    {
    }

    template <class T1, class T2>
    pair<T1, T2>::~pair()
    {
    }

};

#endif
