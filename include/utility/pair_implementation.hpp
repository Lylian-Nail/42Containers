/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair_implementation.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 07:49:46 by lperson-          #+#    #+#             */
/*   Updated: 2022/03/28 09:08:17 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_IMPLEMENTATION_HPP

# define PAIR_IMPLEMENTATION_HPP

namespace ft
{
    /*
     * Constructors and destructor
    */

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
    pair<T1, T2>::pair(first_type const &first, second_type const &second):
        first(first),
        second(second)
    {
    }

    template <class T1, class T2>
    pair<T1, T2>::~pair()
    {
    }

    /*
     * Operator overloads
    */

    template <class T1, class T2>
    pair<T1, T2> &pair<T1, T2>::operator=(pair const &rhs)
    {
        if (this != &rhs)
        {
            first = rhs.first;
            second = rhs.second;
        }
        return *this;
    }

    /*
     * Non member operator overloads
    */

    template <class T1, class T2>
    bool operator==(pair<T1, T2> const &lhs, pair<T1, T2> const &rhs)
    {
        return lhs.first == rhs.first && lhs.second == rhs.second;
    }

    template <class T1, class T2>
    bool operator!=(pair<T1, T2> const &lhs, pair<T1, T2> const &rhs)
    {
        return !(lhs == rhs);
    }

    template <class T1, class T2>
    bool operator<(pair<T1, T2> const &lhs, pair<T1, T2> const &rhs)
    {
        return
            lhs.first < rhs.first ||
            (!(rhs.first < lhs.first) && lhs.second < rhs.second);
    }

    template <class T1, class T2>
    bool operator>(pair<T1, T2> const &lhs, pair<T1, T2> const &rhs)
    {
        return !(lhs < rhs);
    }
}

#endif
