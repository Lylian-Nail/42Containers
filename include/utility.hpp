/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 07:40:14 by lperson-          #+#    #+#             */
/*   Updated: 2022/03/28 09:22:53 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP

# define UTILITY_HPP

# include "utility/pair_definition.hpp"
# include "utility/pair_implementation.hpp"

namespace ft
{
    template <class T1, class T2>
    pair<T1, T2> make_pair(T1 first, T2 second)
    {
        return pair<T1, T2>(first, second);
    }
};

#endif
