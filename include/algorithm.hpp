/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:47:20 by lperson-          #+#    #+#             */
/*   Updated: 2022/02/23 14:17:44 by lperson-         ###   ########.fr       */
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
};

#endif
