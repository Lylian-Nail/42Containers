/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_implementation.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:00:58 by lperson-          #+#    #+#             */
/*   Updated: 2022/04/05 09:09:07 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_IMPLEMENTATION_HPP

# define ITERATOR_IMPLEMENTATION_HPP

// Use namespace to private scope for template functions
namespace iterator_implementation
{

    /*
     * We use iterator tags to differentiate different implementations
     * of same functions and choose correct algorithm for the iterator
     * 
     * Thanks to polymorphism and function overload :-D
    */

    template <class InputIterator>
    typename ft::iterator_traits<InputIterator>::difference_type
        distance(
                InputIterator first, InputIterator last,
                std::random_access_iterator_tag const &
            )
    {
        return last - first;
    }

    template <class InputIterator>
    typename ft::iterator_traits<InputIterator>::difference_type
        distance(
                InputIterator first, InputIterator last,
                std::input_iterator_tag const &
            )
    {
        typename ft::iterator_traits<InputIterator>::difference_type    i;
        for (i = 0; first != last; first++, ++i)
            ;
        return i;
    }
}

#endif
