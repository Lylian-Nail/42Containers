/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BinarySearchTree_definition.hpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperson- <lperson-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 09:53:41 by lperson-          #+#    #+#             */
/*   Updated: 2022/04/08 13:11:30 by lperson-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_SEARCH_TREE_DEFINITION_HPP

# define BINARY_SEARCH_TREE_DEFINITION_HPP

# include <memory>
# include <functional>
# include "utility.hpp"
# include "iterator.hpp"
# include "type_traits.hpp"

namespace ft
{
    /*
     * The binary search tree class
     * A simple and naive binary search tree class
    */

    template <
        class T,
        class Compare = std::less<T>,
        class Alloc = std::allocator<T>
    >
    class BinarySearchTree
    {
    protected:
        class Node;
        template <class Node, class Type>
        class in_order_iterator;

    public:
        /*
        * Template base public aliases
        */
        typedef T                                           value_type;
        typedef Compare                                     value_compare;
        typedef Alloc                                       allocator_type;
        typedef typename allocator_type::reference          reference;
        typedef typename allocator_type::const_reference    const_reference;
        typedef typename allocator_type::pointer            pointer;
        typedef size_t                                      size_type;
        typedef typename allocator_type::const_pointer      const_pointer;

    protected:
        typedef typename allocator_type::rebind<Node>::other
                                            node_allocator_type;
        typedef typename node_allocator_type::value_type 
                                            node_type;
        typedef typename node_allocator_type::pointer
                                            node_pointer;
        typedef typename node_allocator_type::const_pointer
                                            node_const_pointer;
        typedef typename node_allocator_type::reference
                                            node_reference;
        typedef typename node_allocator_type::const_reference
                                            node_const_reference;

    public:
        typedef in_order_iterator<node_pointer, pointer>
                                            iterator;
        typedef in_order_iterator<node_const_pointer, const_pointer>
                                            const_iterator;
        typedef ft::reverse_iterator<iterator>
                                            reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>
                                            const_reverse_iterator;

        /*
         * Constructors and destructors
        */

        explicit BinarySearchTree(
            value_compare const &compare = value_compare(),
            allocator_type const &allocator = allocator_type()
        );
        template <class InputIterator>
        BinarySearchTree(
            typename enable_if<
                !is_integral<InputIterator>::value, InputIterator
            >::type first,
            InputIterator last,
            value_compare const &compare = value_compare(),
            allocator_type const &allocator = allocator_type()
        );
        BinarySearchTree(BinarySearchTree const &copy);
        virtual ~BinarySearchTree();

        /*
         * Getters
        */

        value_compare value_comp() const;
        allocator_type get_allocator() const;
        bool empty() const;
        size_type size() const;
        size_type max_size() const;
        size_type count(const_reference value) const;
        const_iterator find(const_reference value) const;
        const_iterator lower_bound(const_reference value) const;
        const_iterator upper_bound(const_reference value) const;
        ft::pair<const_iterator, const_iterator> equal_range(
            const_reference value
        ) const;

        /*
         * Setters
        */

        pair<iterator, bool> insert(const_reference value);
        iterator insert(iterator position, const_reference value);
        template <class InputIterator>
        void insert(
            typename enable_if<
                !is_integral<InputIterator>::value, InputIterator
            >::type first,
            InputIterator last
        );
        void erase(iterator position);
        size_type erase(const_reference value);
        void erase(iterator first, iterator last);
        void clear();
        void swap(BinarySearchTree &swapped);
        iterator find(const_reference value);
        iterator lower_bound(const_reference value);
        iterator upper_bound(const_reference value);
        ft::pair<iterator, iterator> equal_range(const_reference value);

        /*
         * Iterators
        */

        iterator begin();
        const_iterator begin() const;

        iterator end();
        const_iterator end() const;

        reverse_iterator rbegin();
        const_reverse_iterator rbegin() const;

        reverse_iterator rend();
        const_reverse_iterator rend() const;

        /*
         * Operator overload
        */

        BinarySearchTree &operator=(BinarySearchTree const &rhs);

    protected:
        node_pointer        m_superRoot;
        node_pointer        m_root;
        size_type           m_size;
        value_compare       m_compare;
        allocator_type      m_allocator;
        node_allocator_type m_node_allocator;

        /*
         * Node utilities
         * Theses node utilites can be override in inheritance
        */

        virtual node_pointer create_node(
            const_reference value, node_pointer parent = NULL
        );
        virtual void destroy_node(node_pointer node);

        virtual pair<iterator, bool> insert_node(
            node_pointer root, const_reference value
        );
        virtual void erase_node(node_pointer root, iterator position);
        virtual void clear_node(node_pointer root);

    };
}
#endif
