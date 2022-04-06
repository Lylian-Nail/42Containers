/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_definition.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:44:10 by lperson-          #+#    #+#             */
/*   Updated: 2022/04/06 11:21:34 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_DEFINITION_HPP

# define MAP_DEFINITION_HPP

# include "binary_trees/BinarySearchTree.hpp"

namespace ft
{

    template <
        class Key,
        class T,
        class Compare = std::less<Key>,
        class Alloc = std::allocator<pair<const Key, T> >
    >
    class map
    {
        /*
         * Member types definitions
        */
    public:
        struct value_compare;

        typedef Key                                         key_type;
        typedef T                                           mapped_type;
        typedef pair<key_type const, mapped_type>           value_type;
        typedef Compare                                     key_compare;
        typedef Alloc                                       allocator_type;
        typedef typename allocator_type::reference          reference;
        typedef typename allocator_type::const_reference    const_reference;
        typedef typename allocator_type::pointer            pointer;
        typedef typename allocator_type::const_pointer      const_pointer;

    private:
        /*
         * The binary search tree used internally
        */

        typedef BinarySearchTree<
            value_type, value_compare, allocator_type
        >   tree_type;

    public:
        typedef typename tree_type::iterator                iterator;
        typedef typename tree_type::const_iterator          const_iterator;
        typedef typename tree_type::reverse_iterator        reverse_iterator;
        typedef typename tree_type::const_reverse_iterator
                                    const_reverse_iterator;
        typedef typename iterator_traits<iterator>::difference_type
                                                    difference_type;
        typedef std::size_t                                  size_type;
    };
}

#endif
