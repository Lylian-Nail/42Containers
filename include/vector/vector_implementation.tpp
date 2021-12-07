/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_implementation.tpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 10:37:54 by lperson-          #+#    #+#             */
/*   Updated: 2021/12/07 12:06:41 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_IMPLEMENTATION_HPP

# define VECTOR_IMPLEMENTATION_HPP

# include "../vector.hpp"

/*
 * Ctors
*/

template <class T, class Allocator>
ft::vector<T, Allocator>::vector():
        _allocator()
{}

template <class T, class Allocator>
ft::vector<T, Allocator>::vector(size_type n, value_type const &val):
        _allocator(),
        _size(n)
{
    _datas = _allocator.allocate(n);
    for (size_type i(0); i < _size; ++i)
        _allocator.construct(_datas + i, val);
}

template <class T, class Allocator>
template <class InputIterator>
ft::vector<T, Allocator>::vector(InputIterator first, InputIterator last):
        _allocator()
        _size(std::distance(first, last))
{
    _datas = _allocator.allocate(_size);
    for (size_type i(0); first != last; first++, ++i)
    {
        _allocator.construct(_datas + i, *first);
    }
}

template <class T, class Allocator>
ft::vector<T, Allocator>::vector(vector<T, Allocator> const &copy):
        _allocator(copy.get_allocator()),
        _size(copy.size())
{
    
}

/*
 * Getters
*/

template <class T, class Allocator>
ft::vector<T, Allocator>::allocator_type
    ft::vector<T, Allocator>::get_allocator() const
{
    return _allocator;
}

template <class T, class Allocator>
ft::vector<T, Allocator>::size_type
    ft::vector<T, Allocator>::size() const
{
    return _size;
}

template <class T, class Allocator>
ft::vector<T, Allocator>::size_type
    ft::vector<T, Allocator>::max_size() const
{
    return _allocator.max_size();
}

#endif
