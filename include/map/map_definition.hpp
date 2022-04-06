/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_definition.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:44:10 by lperson-          #+#    #+#             */
/*   Updated: 2022/04/06 13:40:06 by lperson-         ###   ########.fr       */
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
        class   value_compare;

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

        /*
         * Constructors and destructor
        */

        explicit map(
            key_compare const &key_compare = key_compare(),
            allocator_type const &allocator = allocator_type()
        );

        /*
         * Getters
        */

        bool empty() const;
        size_type size() const;
        size_type max_size() const;
        key_compare key_comp() const;
        value_compare value_comp() const;
        allocator_type get_allocator() const;

    private:
        key_compare     m_key_compare;
        value_compare   m_value_compare;
        tree_type       m_tree;

    };
}

#endif
