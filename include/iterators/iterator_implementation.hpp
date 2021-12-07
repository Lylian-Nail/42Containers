/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_implementation.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:00:58 by lperson-          #+#    #+#             */
/*   Updated: 2021/12/07 14:35:25 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_IMPLEMENTATION_HPP

# define ITERATOR_IMPLEMENTATION_HPP

// Use namespace to private scope for template functions
namespace iterator_implementation
{

    /*
     * We use iterator tags to differentiates differents implementations
     * of same functions and choose correct algorithm for the iterator
     * 
     * Thanks to polymorphism and function overload :-D
    */

    template <class InputIterator>
    typename iterator_traits<InputIterator>::difference_type
        distance(
                InputIterator first, InputIterator last,
                random_access_iterator_tag const &
            )
    {
        return last - first;
    }

    template <class InputIterator>
    typename iterator_traits<InputIterator>::difference_type
        distance(
                InputIterator first, InputIterator last,
                input_iterator_tag const &
            )
    {
        typename iterator_traits<InputIterator>::difference_type    i;
        for (i = 0; first < last; first++, ++i)
            ;
        return i;
    }
};

#endif
