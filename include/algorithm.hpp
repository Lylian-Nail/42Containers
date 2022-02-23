/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:47:20 by lperson-          #+#    #+#             */
/*   Updated: 2022/02/23 14:43:56 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_HPP

# define ALGORITHM_HPP

# include "type_traits.hpp"

namespace ft
{
    template <class InputIterator1, class InputIterator2>
    bool equal(
        typename enable_if<
            !is_integral<InputIterator1>::value, InputIterator1
        >::type first1,
        InputIterator2 last1,
        typename enable_if<
            !is_integral<InputIterator2>::value, InputIterator2
        >::type first2
    )
    {
        for (; first1 != last1; ++first1, ++first2)
        {
            if (*first1 != *first2)
                return false;
        }
        return true;
    }

    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare(
        typename enable_if<
            !is_integral<InputIterator1>::value, InputIterator1
        >::type first1,
        InputIterator1 last1,
        typename enable_if<
            !is_integral<InputIterator2>::value, InputIterator2
        >::type first2,
        InputIterator2 last2
    )
    {
        for (; first1 != last1; ++first1, ++first2)
        {
            if (first2 == last2 || *first2 < *first1)
                return false;
            else if (*first1 < *first2)
                return true;
        }
        return first2 != last2;
    }
};

#endif
