/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:08:20 by lperson-          #+#    #+#             */
/*   Updated: 2021/12/07 15:24:13 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP

# define ITERATOR_HPP

# include <cstddef>

# include <iterators/base_iterator.hpp>
# include <iterators/iterator_traits.hpp>
# include <iterators/normal_iterator.hpp>
# include <iterators/iterator_implementation.hpp>

namespace ft
{
    /*
     * Defines some functions for iterators
    */

    template <class InputIterator>
    typename iterator_traits<InputIterator>::difference_type
        distance(InputIterator first, InputIterator last)
    {
        return iterator_implementation::distance(
                first, last,
                typename iterator_traits<InputIterator>::iterator_category()
            );
    }
}

#endif
