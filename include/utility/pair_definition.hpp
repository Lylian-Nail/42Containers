/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair_definition.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 07:40:59 by lperson-          #+#    #+#             */
/*   Updated: 2022/03/28 07:45:24 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_DEFINITION_HPP

# define PAIR_DEFINITION_HPP

namespace ft
{
    template <class T1, class T2>
    struct pair
    {
        typedef T1      first_type;
        typedef T2      second_type;

        first_type first;
        second_type second;

        /*
         * Constructor and destructor
        */
        pair();
        template <class U, class V>
        pair(pair<U, V> const &copy);
        pair(first_type const &first, second_type const &second);
        ~pair();

    };
};

#endif
