/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_compare_definition.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:22:48 by lperson-          #+#    #+#             */
/*   Updated: 2022/04/06 11:25:47 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALUE_COMPARE_DEFINITION_HPP

# define VALUE_COMPARE_DEFINITION_HPP

namespace ft
{
    template <class Key, class T, class Compare, class Alloc>
    struct map<Key, T, Compare, Alloc>::value_compare
    {
    };
}

#endif
